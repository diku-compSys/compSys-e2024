%.riscv: %.c lib.c Makefile
	./gcc -march=rv32im -mabi=ilp32 -fno-tree-loop-distribute-patterns -O1 $< lib.c -static -nostartfiles -nostdlib -o $@

%.riscv: %.s Makefile
	./gcc -march=rv32im -mabi=ilp32 -fno-tree-loop-distribute-patterns -O1 $< -static -nostartfiles -nostdlib -o $@

%.dis: %.riscv Makefile
	./objdump -s -w $< > $@
	./objdump -S $< >> $@
