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
In this exercise, you will complete the implementation of a peer-to-peer chat program using TCP sockets in C. The provided code already includes the structure and setup for creating and binding sockets, starting a listening server, and running a separate thread to handle incoming messages.

Each peer should be able to send and receive messages simultaneously, enabling basic chat functionality. Multiple instances of the program should be able to run in separate terminal windows to form a peer-to-peer network.

**What you need to do:**
1. Implement the sending() function to allow peers to send messages to other peers using their port numbers.
2. Implement the receiving() function to handle incoming messages from other peers.

**Limitation**  <br>
The program requires the user to know the port numbers of other users on the same localhost beforehand. 

**Simultaneous send and receive** <br>
The program achieves simultaneous send and receive functionality by creating a dedicated thread to handle incoming messages. Each peer listens for connections while allowing the user to send messages in parallel.

**Running instructions** <br>
The program can be executed on a Linux system using gcc compiler.

```
gcc peer.c -o peer1
gcc peer.c -o peer2
./peer1
./peer2
```
