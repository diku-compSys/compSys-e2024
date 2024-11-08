# Exercises for DNS

## Exercises from Chapter 2 of Kurose and Ross on "Application Layer"
* P19
  * Read the dig and nslookup man pages. [This short tutorial on dig](https://www.linode.com/docs/networking/dns/use-dig-to-perform-manual-dns-queries/) might be of interest to you.
  * You can install it by installing [bind-tools](http://www.isc.org/downloads/bind/) package if you are on a UNIX machine or the client bind tools for Windows. 
* P21
* P26

## Create a C programme for DNS lookups
Use the C functions getaddrinfo (https://man7.org/linux/man-pages/man3/gai_strerror.3.html) and (https://man7.org/linux/man-pages/man3/inet_ntop.3.html) to create a program that takes a human readable address such as 'www.google.com', converts it into an appropriate IP address, and prints it to the user.

## Peer to peer program in C
This program involves a peer which can send and receive simultaneously, created using Socket programming in C. Multiple instances of the code can be run in seperate terminal environments to form a peer to peer chat network.

**Limitations**
1. The program requires the user to know the port numbers of other users on the same localhost beforehand. 
2. The program is just a demonstration of TCP/IP Socket programming in C.

**Simultaneous send and receive** <br>
The program achieves simultaneous send and receive by running the receive method on seperate thread. The program involves the use of **select()** system call to identify the ready file descriptors and loop over them to receive the messages in queue. However, this simultaneous send and receive is not refined and may interrupt the user while sending the message. 

**Running instructions** <br>
The program can be executed on a Linux system using gcc compiler.

```
gcc peer.c -o peer1
gcc peer.c -o peer2
./peer1
./peer2
```
