# Exercises

1. Get the 'C' examples and setup for cross compiling 

They are placed in our public repo in the "resources/tiny_riscv" directory.
Copy all files in that directory to where you want to work with them.

We're using tools on a server at DIKU to provide uniform setup to everybody,
so internet access is required.



1B. (Optional) Install tools locally

IF YOU WISH to run the cross compiler without internet access you'll have to
install your own. The prebuild cross compiler can be found at:

https://github.com/stnolting/riscv-gcc-prebuilt

1C. (Optional) Modify the Makefile to fit your own installation.

(Only do this if you install local tools - not if you are using the server)

The Makefile currently refers to "./gcc" for the cross compiler and
"./objdump" for the objdump utility. You need to change this to
match your installation. 

As an example, the makefile on Mac may look like the following (depending on where you have installed the RISCV-gnu-toolchain):

```makefile
%.riscv: %.c lib.c Makefile
	/usr/local/opt/riscv-gnu-toolchain/bin/riscv64-unknown-elf-gcc  -march=rv32im -mabi=ilp32 -fno-tree-loop-distribute-patterns -mno-relax -O1 $< lib.c -static -nostartfiles -nostdlib -o $@

%.dis: %.riscv Makefile
	/usr/local/opt/riscv-gnu-toolchain/bin/riscv64-unknown-elf-objdump -s -w $< > $@
	/usr/local/opt/riscv-gnu-toolchain/bin/riscv64-unknown-elf-objdump -S $< >> $@
```



2. Compile your first C program

Translate fib.c into a disassembled riscv format (.dis)
by running "make fib.dis". Look at the generated file and try to figure out, what's in it.


3. Earlier in the course you wrote your own fib function in riscv
assembly. Find your own code from back then and compare it to the
generated code. Alternately write it again.


4. In the Makefile several different options are given to the cross compiler,
among them "-O1" - this yields a program that is reasonably fast while also
typically being relatively readable. By changing the option you can get
no optimization (-O0) or more optimization (-O2). Try generating riscv assembler
for each of these 3 optimization levels. Compare them against each other. 
Which is more readable? We can expect -O2 to be faster then the others. But how much
(guess) ?

5. Try to understand the minimal library in "lib.c"

Perhaps break it up and ask chatgpt to explain the fragments one by one.
Be critical.


--------------------------

The riscv simulator is needed for the next exercises, but it is not working yet. It should be working Monday


6. Use the riscv simulator.

The simulator resides on the server and is accessed by the sim.py script in
the "resources/tiny_riscv" directory.

Use the simulator to run your 3 variants of fib and find out how many
instructions it takes to run each variant with the same input.
Check the source code in fib.c to discover how it gets its input.


7. Write your own C program

Try to use some of the facilities, for example input/output.
Note that there is no standard library. Only the functions defined in "lib.h"
is available.

Take a look at hello.c, fib.c, erat.c or echo.c for inspiration.

If you're really ambitious, try to build something which uses the dynamic memory
management as well (allocate/release).

When things go wrong it is insanely difficult to find out why.

 * You can use the logging facility to see how far in the execution you got.
 * Best approach to debugging is to put in print_string() calls at the right
   places in your program.

