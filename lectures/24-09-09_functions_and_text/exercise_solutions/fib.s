init:
        # fib(7)
        li a0, 7
        jal ra, fib

        # Exit
        jal zero, end

fib:
        # Callee saves stack variables 
        addi sp, sp, -12        # Prepare enough stack space for 3 variables * 4 bytes 
        sw ra, 8(sp)            # Save return address on the stack
        sw a0, 4(sp)            # Save function argument on the stack
        
        # if (a0 < 3) { return 1; }
        li t0, 3
        blt a0, t0, base

        # int x = fib(a0 - 1)
        addi a0, a0, -1
        jal ra, fib
        sw a0, 0(sp) 
        lw a0, 4(sp)
        
        # int y = fib(a0 - 2)
        addi a0, a0, -2
        jal ra, fib
        lw t0, 0(sp)
        
        # return x + y
        add a0, t0, a0
        jal zero, return
base:
        # Base case: if (a0 < 3)
        li a0, 1
return:
        # Restore saved stack variables
        lw ra, 8(sp)            # Load stored return address
        addi sp, sp, 12         # Remove stack space for 3 variables * 4 bytes
        jalr zero, ra, 0        # Return to caller

end:
