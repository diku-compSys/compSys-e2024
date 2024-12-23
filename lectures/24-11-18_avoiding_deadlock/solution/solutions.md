# Exercises for performant servers

8.15
8.23
12.17
12.18
12.27
12.29

## Theory tasks

### Q1

0 is showing a process, P shows when it prints within the try function, F when it prints within the main

    0
    | \
    0  0
    |  |  \
    F  0    0
       | \  | \
       P  P P  P
       |  | |  |
       F  F F  F

9 print statemens will be produced

### Q2

Signals are not queued for standard UNIX signals, so only one additional signal can be remembered while a process is handling a signal.   
So if a process is busy handling a signal, and another signal gets sendt. The extra signal will be remembered, but any more signals, will get coalesced/ignored.  

In reality this is indeterministic and the counter can take different values, it just so happens that 2 is the most common in this case, due to the timing.  
Communication between parent and child using signals is not guarenteed to be stable.  
For stable communication threads can be used.   

Try changing or removing the sleep in handle, and see how the counter takes different values between runs. Or try adding a sleep in the child for loop. 


### Q3

The main never waits for the thread to complete before exiting. Once the parent exits, the orphan child thread will be automatically killed.

### Q4

pthread_join(&tid) and pthread_exit(0) could be used together to wait for the given thread to finish before proceeding

### Q5

A = unsafe
B = safe
C = unsafe

### Q6

Problem is that multiple threads have access to close the descriptor twice.

Multiple issues related to concurrency:
Both fpin and fpout might be accessed concurrently by multiple threads.

if one thread is reading from fpin while another is writing to fpout, there's a potential for data corruption, interleaving, or other unexpected behavior.

The C standard library does not guarantee that FILE streams are thread-safe. Therefore, concurrent access to the same FILE streams from multiple threads can result in undefined behavior.

race condition:   If one thread is still using the streams while another thread closes them, it can lead to issues such as accessing a closed stream, resource conflicts, or undefined behavior.


### Q7

No, a process graph shows there is no deadlockable state that can be reached
