#ifndef __READ_ELF_H__
#define __READ_ELF_H__

#include "memory.h"

#include <stdio.h>

struct program_info {
    unsigned int text_start;
    unsigned int text_end;
    unsigned int start;
};

// read file into simulated memory, fill in program info
int read_elf(struct memory* mem, struct program_info* info, const char* file_name, FILE *log_file);

struct symbols;

// read symbol table from elf file
struct symbols* symbols_read_from_elf(const char* file_name);

// delete symbol table after use
void symbols_delete(struct symbols* symbols);

// map a value to a symbol (return NULL if no matching symbol found)
const char* symbols_value_to_sym(struct symbols* symbols, unsigned int value);


#endif
