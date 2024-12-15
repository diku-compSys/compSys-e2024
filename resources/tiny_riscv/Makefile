PYTHON = python3 # or just 'python' on some platforms

%.riscv: %.c lib.c Makefile
	$(PYTHON) ./gcc.py -march=rv32im -mabi=ilp32 -fno-tree-loop-distribute-patterns -O1 $< lib.c -static -nostartfiles -nostdlib -o $@

%.riscv: %.s Makefile
	$(PYTHON) ./gcc.py -march=rv32im -mabi=ilp32 -fno-tree-loop-distribute-patterns -O1 $< -static -nostartfiles -nostdlib -o $@

%.dis: %.riscv Makefile
	$(PYTHON) ./objdump.py -s -w $< > $@
	$(PYTHON) ./objdump.py -S $< >> $@

