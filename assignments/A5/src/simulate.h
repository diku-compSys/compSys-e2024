#ifndef __SIMULATE_H__
#define __SIMULATE_H__

#include "memory.h"
#include "read_elf.h"
#include <stdio.h>

// Simuler RISC-V program i givet lager og fra given start adresse
struct Stat { long int insns; };

struct Stat simulate(struct memory *mem, int start_addr, FILE *log_file, struct symbols* symbols);

#endif
