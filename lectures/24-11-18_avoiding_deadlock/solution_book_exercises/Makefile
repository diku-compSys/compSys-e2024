#GCC=gcc -O3 -g -Wall -Wextra -pedantic -std=gnu11
GCC=gcc -g -Wall -Wextra -pedantic -std=gnu11

all: forking signalparent

rebuild: clean all

forking: forking.c 
	$(GCC) forking.c -o forking

signalparent: signalparent.c 
	$(GCC) signalparent.c -o signalparent



zip: ../src.zip

../src.zip: clean
	cd .. && zip -r src.zip src/Makefile src/*.c src/*.h

clean:
	rm -rf *.o forking vgcore* signalparent
