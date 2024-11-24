# Exercises


1 - 5. Any of exercises 1-5 from last week, if you haven't done them.

Now install the riscv simulator.

At this point it will (contrary to earlier claims) not be available as a service.

Instead you'll have to get it from the directory 'tools/riscv-sim' in the public repo.
In this directory, there should be one Linux executable and one Mac executable. Pick
the one matching your setup.

(The Mac one will likely not be ready before exercises Monday)


6. Use the riscv simulator.

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


