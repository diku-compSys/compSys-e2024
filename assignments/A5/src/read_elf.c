#include "read_elf.h"
#include "disassemble.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elf.h"

int read_elf(struct memory* mem, struct program_info* info, const char *filename, FILE *log_file) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(log_file, "Error opening file");
        return -1;
    }

    // Read the ELF header
    Elf32_Ehdr elf_header;
    unsigned stat = fread(&elf_header, 1, sizeof(Elf32_Ehdr), file);
    if (stat != sizeof(Elf32_Ehdr)) {
        fprintf(log_file, "Elf file error, file shorter than minimal header size.\n");
        fclose(file);
        return -1;
    }

    // Check for ELF magic number
    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(log_file, "Not a valid ELF file.\n");
        fclose(file);
        return -1;
    }

    // Seek to the program header table and read program headers
    info->text_start = 0;
    info->text_end = 0;
    info->start = elf_header.e_entry;
    //printf("Program headers starting at offset %d\n", elf_header.e_phoff);
    //printf("Program entry point address: 0x%x\n", info->start);
    //printf("Text offset 0x%x\n\n", info->text_start);
    Elf32_Phdr program_header;
    for (int i = 0; i < elf_header.e_phnum; i++) {
        fseek(file, elf_header.e_phoff + i * sizeof(Elf32_Phdr), SEEK_SET);
        stat = fread(&program_header, 1, sizeof(Elf32_Phdr), file);
        if (stat != sizeof(Elf32_Phdr)) {
            fprintf(log_file, "Elf file error, file shorter than minimal prog header size.\n");
            fclose(file);
            return -1;
        }

        // Check for loadable segments (PT_LOAD)
        if (program_header.p_type == PT_LOAD) {
            // const char *segment_type = NULL;

            // Identify segment type
            if (program_header.p_flags & PF_X) {
                // segment_type = "Executable (.text)";
                info->text_start = program_header.p_vaddr + (unsigned int)(sizeof(Elf32_Ehdr) + elf_header.e_phnum * sizeof(Elf32_Phdr));
                info->text_end = program_header.p_vaddr + program_header.p_filesz;
            } else if (program_header.p_flags & PF_W) {
                // segment_type = "Writable (static data)";
            } else {
                // segment_type = "Read-only (e.g., .rodata)";
            }

            //printf("Found %s segment at offset 0x%x, size 0x%x, in-memory address 0x%x\n",
            //      segment_type, program_header.p_offset, program_header.p_filesz, program_header.p_vaddr);

            // Allocate buffer for the segment
            unsigned char *segment_data = malloc(program_header.p_filesz);
            if (!segment_data) {
                fprintf(log_file, "Error allocating memory for segment\n");
                fclose(file);
                return -1;
            }

            // Read the segment data
            fseek(file, program_header.p_offset, SEEK_SET);
            stat = fread(segment_data, 1, program_header.p_filesz, file);
            if (stat != program_header.p_filesz) {
                fprintf(log_file, "Error reading segment - failed to read entire segment in one go\n");
                return -1;
            }

            // Process the segment data (e.g., print or analyze)
            // printf("All bytes of %s segment:\n", segment_type);
            for (unsigned int j = 0; j < program_header.p_filesz; j++) {
                // printf("%02x ", segment_data[j]);
                memory_wr_b(mem, program_header.p_vaddr + j, segment_data[j]);
            }
            /*
            printf("\n\nDisassembly\n");
            for (unsigned int j = info->text_start; j < program_header.p_filesz; j += 4) {
                unsigned int addr = program_header.p_vaddr + j;
                int inst = memory_rd_w(mem, addr);
                const int buf_sz = 64;
                char buf[buf_sz];
                decode_rv32i(addr, inst, buf, buf_sz);
                // printf("%6x %8x   %s\n", j, inst, buf);
            }
            printf("\n");
            */
            free(segment_data);
        }
    }
    // adjust program info to virtual addresses instead of file offsets
    fclose(file);
    return 0;
}

struct symbols {
    char* strtab;
    Elf32_Sym* symbols;
    int num_symbols;
};

struct symbols* symbols_read_from_elf(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Read the ELF header
    Elf32_Ehdr elf_header;
    int status = fread(&elf_header, 1, sizeof(Elf32_Ehdr), file);
    if (status != sizeof(Elf32_Ehdr)) {
        fprintf(stderr, "Not a valid ELF file.\n");
        fclose(file);
        return NULL;
    }

    // Check for ELF magic number
    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Not a valid ELF file.\n");
        fclose(file);
        return NULL;
    }

    // Seek to the section header table
    fseek(file, elf_header.e_shoff, SEEK_SET);

    // Read all section headers
    Elf32_Shdr *section_headers = malloc(elf_header.e_shnum * sizeof(Elf32_Shdr));
    status = fread(section_headers, elf_header.e_shnum, sizeof(Elf32_Shdr), file);
    if (status != sizeof(Elf32_Shdr)) {
        fprintf(stderr, "While reading ELF file: Invalid section header.\n");
        fclose(file);
        return NULL;
    }

    // Locate the symbol table and the string table
    Elf32_Shdr *symtab_section = NULL;
    Elf32_Shdr *strtab_section = NULL;
    for (int i = 0; i < elf_header.e_shnum; i++) {
        if (section_headers[i].sh_type == SHT_SYMTAB) {
            symtab_section = &section_headers[i];
        } else if (section_headers[i].sh_type == SHT_STRTAB && i != elf_header.e_shstrndx) {
            // Avoid the section header string table
            strtab_section = &section_headers[i];
        }
    }

    if (!symtab_section || !strtab_section) {
        fprintf(stderr, "No symbol table found.\n");
        free(section_headers);
        fclose(file);
        return NULL;
    }

    struct symbols* symbols = malloc(sizeof(struct symbols));
    // Read the string table
    symbols->strtab = malloc(strtab_section->sh_size);
    fseek(file, strtab_section->sh_offset, SEEK_SET);
    status = fread(symbols->strtab, 1, strtab_section->sh_size, file);
    if ((unsigned int)status != strtab_section->sh_size) {
        fprintf(stderr, "Error, unable to read string table in one go.\n");
        fclose(file);
        return NULL;
    }

    // Read the symbol table entries
    symbols->num_symbols = symtab_section->sh_size / sizeof(Elf32_Sym);
    symbols->symbols = malloc(symtab_section->sh_size);
    fseek(file, symtab_section->sh_offset, SEEK_SET);
    status = fread(symbols->symbols, symbols->num_symbols, sizeof(Elf32_Sym), file);
    if (status != sizeof(Elf32_Sym)) {
        fprintf(stderr, "Error, unable to read symbol table entry.\n");
        fclose(file);
        return NULL;
    }

    // Print symbols
    /* printf("Symbols:\n");
    for (int i = 0; i < symbols->num_symbols; i++) {
        const char *name = &symbols->strtab[symbols->symbols[i].st_name];
        printf("Name: %-50s Address: 0x%-8x Size: %3d Type: %2d Binding: %2d\n",
               name,
               symbols->symbols[i].st_value,
               symbols->symbols[i].st_size,
               ELF32_ST_TYPE(symbols->symbols[i].st_info),
               ELF32_ST_BIND(symbols->symbols[i].st_info));
    }
    */
    // Free allocated memory
    // free(strtab);
    // free(symbols);
    free(section_headers);
    fclose(file);
    return symbols;
}


const char* symbols_value_to_sym(struct symbols* symbols, unsigned int value) 
{
    for (int i = 0; i < symbols->num_symbols; i++) {
        if (symbols->symbols[i].st_value == value && ELF32_ST_BIND(symbols->symbols[i].st_info)) {
            return &symbols->strtab[symbols->symbols[i].st_name];
        }
    }
    return NULL;
}

