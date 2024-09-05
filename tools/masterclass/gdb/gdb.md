# GDB
GDB is a tool, that can help with debugging programs. It can save you, creating multiple print statements such as
 ```(printf("we get here \n"))``` , ```(printf("we get here 2 \n"))```, etc.

GDB has many, many functionalites and utilities, enough to have its own course, but here we will only sratch the surface, with the basic functionalites, such as setting breakpoints, and printing variables and values


## Installing
If you use linux for windows, or linux, it is easy, just use the command `apt-get install gdb" and everything should work.

If youre using MAC, you might need to use homebrew, please follow this [guide](https://ics.uci.edu/~pattis/common/handouts/macmingweclipse/allexperimental/mac-gdb-install.html).

If you are using windows, please install linux for windows, and see linux. To do this please refer to the tools section


## Starting gdb
To use gdb you simply use the command ```gdb```. To then specify a file you can then inside gdb use `file myfile`. Otherwise you could simply give the file when starting `gdb myfile`

From here you should be able to run the program by simply doing `run`, or if you need command line arguments `run arg1 arg2`.

you can quit gdb with the `quit` command or `q`.

<span style="color:red;">EXERCISE:</span>
use gdb on the debug program and run it, see what the result is, and if there is indications on any bugs / errors.

## Breakpoints
To examine the program, we can ask gdb to stop the execution of the program at certain points, these are called break points.

To set a break point you simply use the `break n` or `b n` for short, with n being the line number

<span style="color:red;">EXERCISE:</span>
Set a couple break points where it makes sense in the debug program, you can use the comments in the .c file as inspiration.

## Continue (c), next (n)
To continue after a coming to a break point, you can use the `continue` or `c` command. This will continue execution until the next breakpoint. Breakpoints in loops will be encountered until you exit the loop

otherwise you can use the `next` or `n` to only do the next instruction and then pause the executiion again.

<span style="color:red;">EXERCISE:</span> 
Play around with breakpoints, continue and next. Do you understand the difference of next and continue?

why is the next command useful ?

## Printing & examining
It is useful to follow the values of variables during the execution. To do this we can use the print command `print var` or `p var`.

You can also print in specif formats e.g `p\x var` will print the result as hex values.

you can also check array values with e.g `p arr[n]` will print the n index of the array

<span style="color:red;">EXERCISE:</span>
print the value of number and numPointer, what is the difference between these two?

Print the values of the array, after it has been declared, what does these numbers mean, if anything?

print the value of number after the first 3 iteration of the loop, what does the loop seem to do?


## Debugging
<span style="color:red;">EXERCISE:</span>
Now that you know the basics, see if you can debug the program debug.c such that it no longers gives any errors. You can remove the old program with `make clean` and recompile the program with `make debug`

Use the break points and print statemnts to follow the execution and you can use the comments in the .c file for inspiration

(HINT: you can use a watchpoint for a variable, such that execution stops everytime the variale changes, the command for this is `watch var` this might be useful for discovering the bug).