# Lecture plan for Computer Systems

| Week | Date   | Topic | Lecture  | Topic                                                                         | Material |
| ---- | ----   | ----- | -------  | ------                                                                        | -------- |
| 36   | 02 Sep | Intro | David    | Course introduction                                                           | COD 1.1-1.4,1.6-1.8 |
|      |        | Basic | David    | Computers and C programming                                                   | JG 1-3 |
|      | 04 Sep | Basic | David    | Assembly code and machine model                                               | COD 2.1-2.4,2.6-2.7, JG 4 |
|      | 06 Sep |       | TAs      | Master Class on Tools for the Working Programmer, 10-12 in Biocenter 4-0-24                     |  |
| 37   | 09 Sep | Basic | David    | Functions and text                                                            | COD 2.8-2.9, JG 5-7 |
|      | 11 Sep | Basic | David    | Computer arithmetic                                                           | COD 3.1-3.3, 3.5 |
| 38   | 16 Sep | Basic | David    | C Programming - pointers and memory                                           | JG 8-9, 11 |
|      | 18 Sep | Basic | David    | C Programming - dynamic memory                                                | JG 12-13 |
|      |        |       |          | Hand-in A0 -- file(0)                                                         |          |
| 39   | 23 Sep | Basic | David    | Memory hierarchy and caching                                                  | COD 5.1-5.4 |
|      | 25 Sep | OS    | David    | Intro to Operating systems - kernel, processes, system calls                  | OSTEP 2,4,5 |
| 40   | 30 Sep | OS    | David    | Virtual memory - hardware perspective                                         | COD 5.7-5.8 |
|      | 02 Oct | OS    | David    | Virtual memory - OS perspective                                               | OSTEP 13,17 |
|      |        |       |          | Hand-in A1 -- dynamic allocation + caching                                    |          |
| 41   | 07 Oct | OS    | David    | Concurrency I                                                                 | COD 6.1-6.2, 6.4-6.5 and OSTEP 27 |
|      | 09 Oct | OS    | David    | Concurrency II                                                                | OSTEP 29,30 |
| 42   |        |       |          | Fall Vacation - No lectures                                                   |          |
| 43   | 21 Oct | CN    | David    | Introduction to Computer Networks                                             | KR 1.1 - 1.6 (Optional read - [Internet history](https://www.internetsociety.org/internet/history-internet/brief-history-internet/)) |
|      | 23 Oct | CN    | David    | Network Programming                                                           | BOH 11.4 (Optional read - [Beej's Guide to Network Programming](http://beej.us/guide/bgnet/) and BOH 11.1-11.3, 11.6) |
|      |        |       |          | Hand-in A2 -- Concurrency + VM                                                |          |
| 44   | 28 Oct | CN    | David    | Non-Blocking Servers and Introduction to Security                             | BOH 12.1-12.3, KR 8.1, 8.2  |
|      | 30 Oct | CN    | David    | Network Applications: Application Design, Socket API, HTTP & Content Delivery | KR 2.1, 2.2, 2.3.1, 2.3.2, 2.6.1 - 2.6.3 |
| 45   | 04 Nov | CN    | David    | Application Layer: DNS + P2P File Distribution, Transport layer: UDP          | KR 2.4, 2.5, 3.1 - 3.3 |
|      | 06 Nov | CN    | David    | Transport layer: Principles of Reliable Data Transfer + TCP                   | KR 3.1 - 3.7 |
| 46   |        |       |          | Re-exam week - No lectures                                                    |          |
|      |        |       |          | Hand-in A3  -- Simple client, performance, buffering                          |          |
| 47   | 18 Nov | CN    | David    | Avoiding Deadlock                                                             | BOH 12.5-12.7 (Optional read - BOH 8.5-8.7) |
|      | 20 Nov | Arc   | Finn     | C til Assembler - Et minimalt riscv setup                                     | review material for lectures 4/9 + 9/9, slides will be available after lecture |
| 48   | 25 Nov | Arc   | Finn     | RISCV Maskinsprog                                                             | as above. Also get some familiarity/overview of ch 1,2 and 13 of [RISCV](https://github.com/riscv/riscv-isa-manual/releases/download/20240411/unpriv-isa-asciidoc.pdf) |
|      | 27 Nov | Arc   | Finn     | En simpel maskine                                                             | COD 4.1 - 4.4 |
|      |        |       |          | Hand-in A4 -- Threaded Server/application, multi-threaded performance         |  |
| 49   | 02 Dec | Arc   | Finn     | A5 handout. Digital logik                                                     | COD A.1 - A.3, A.5, A7 - A.9, [NandGame](https://nandgame.com/)
|      | 04 Dec | Arc   | Finn     | Into til Mikroarkitektur: Pipelining og ydeevne                               | COD 4.6 - 4.9 |
| 50   | 09 Dec | Arc   | Finn     | Avanceret Mikroarkitektur I                                                   | COD 4.11 + [note](https://github.com/diku-compSys/compSys-e2023-pub/blob/main/resources/Afviklingsplot/plot.md) |
|      | 11 Dec | Arc   | Finn     | Avanceret Mikroarkitektur II                                                  | [note](https://github.com/diku-compSys/compSys-e2023-pub/blob/main/resources/Afviklingsplot/plot.md) |
|      |        |       |          | Hand-in A5                                                                    |  |
| 51   | 16 Dec | Arc   | Finn     | Opsamling. Maskinnær optimering. A6 handout                                   | TBD |
|      | 18 Dec |       |          | Christmas lecture: Anton Folkmann, Netcompany + Perhaps Quantum Computers     |         |
| 52   |        |       |          | Christmas vacation - No lectures                                              |         |
| 53   |        |       |          | Christmas vacation - No lectures                                              |         |
| 1    |        |       |          | Hand-in A6 -- Maskinnær optimering                                            |         |
| 2    | 06 Jan | CN    | Michael  | Network layer, data plane, 13-15, DIKU St.UP1                                 | KR 4.1 - 4.2.4, 4.3 (Optional read - [Design Philosophy of DARPA Internet Protocols](http://www.cs.princeton.edu/courses/archive/spr14/cos461/papers/clark88.pdf)) |
|      | 06 Jan | Recap | TAs      | OS recap, 15-17, NBB 2.0.G.064/070                                            |         |
|      | 08 Jan | CN    | Jakob    | Security Across the Network; 10-12, DIKU St.UP1                               | KR 8.1 - 8.7 |
|      | 08 Jan | CN    | Michael  | Network layer, control plane, 13-15, NBB 2.0.G.064/070                        | KR 5.1 - 5.3, KR 6.1 - 6.4.3, KR 8.5 - 8.6 |
|      | 08 Jan | Recap | TAs      | Computer Network recap, 15-17, NBB 2.0.G.064/070                              |         |
|      | 10 Jan | Recap | TAs      | Computer Architecture, 14-16, NBB 2.0.G.064/070                                             |         |
| 4    | 20 Jan |       | Lectures | Exam question session, recap and evaluation, 13:15 @ ?                        |         |
|      | 22 Jan |       | Everyone | CompSys Exam                                                                  |         |


## Material

 - COD: Computer Organization and Design, RISC-V Edition: The Hardware Software Interface, David A. Hennessy and John L. Patterson, 2nd edition, Morgan Kaufmann, ISBN: 978-0128203316
 - KR: James F. Kurose, Keith W. Ross: Computer Networking: A Top-Down Approach International Edition, 8th and global edition
 - JG: Modern C, Jens Gustedt, Oct. 10, 2019, https://hal.inria.fr/hal-02383654/file/ModernC.pdf
 - OSTEP: Operating Systems: Three Easy Pieces, Remzi H. Arpaci-Dusseau and Andrea C. Arpaci-Dusseau. https://pages.cs.wisc.edu/~remzi/OSTEP/ 
 - BOH: Randal E. Bryant and David R. O'Hallaron. Computer Systems: A Programmers Perspective, 3rd and global edition (We will only use small sections of this book, provided as a pdf with the resources directory. Some additional optional reading is highlighted above for those with access to the full book)


