
#include <stddef.h>
#include <stdint.h>

struct symbols;
void disassemble(uint32_t addr, uint32_t instruction, char* result, size_t buf_size, struct symbols* symbols);
