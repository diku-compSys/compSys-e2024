8.15 (see forking.c for code)
note that the function should be fork() .returns 0 for child process, > 0 is parent process (it is the pid of child)
CORRECT SOLUTION is 9. 

8.23 (see signalparent.c for code)
Signals are not queeed so it will only be counted if the parent process is available. communication between parent and child is not guarenteed to be stable. 
for stable communication threads can be used.


12.17
A and B. 
exit(0) does not wait for threads to terminate and terminates all associated threads. instead include <pthread.h> and use pthread_exit(0) in the peer thread and pthread_join(peer_thread , &result) in the main thread.

12.18 ( fig. 12.21 p 1023)

A. H2,L2,U2,H1,L1, S2,U1, S1, T1, T2: unsafe
B. H2,H1,L1,U1, S1,L2, T1,U2, S2, T2: safe
C. H1,L1,H2,L2,U2, S2,U1, S1, T1, T2: unsafe 


12.27
Problem is that multiple threads have access to close the descriptor twice.

Multiple issues related to concurrency:
Both fpin and fpout might be accessed concurrently by multiple threads.

if one thread is reading from fpin while another is writing to fpout, there's a potential for data corruption, interleaving, or other unexpected behavior.

The C standard library does not guarantee that FILE streams are thread-safe. Therefore, concurrent access to the same FILE streams from multiple threads can result in undefined behavior.

race condition:   If one thread is still using the streams while another thread closes them, it can lead to issues such as accessing a closed stream, resource conflicts, or undefined behavior.


12.29
Thread 1 holds mutex pairs (a, b) and (a, c) simultaneously, but not mutex pair (b,c), 
Thread 2 holds mutex pair (c,b) simultaneously, not the other two. 

The sets are disjoint, there is no deadlock potential. 
