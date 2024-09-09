CFLAGS=-Wall -Wextra -pedantic -std=c11

all: roll noAs guess

roll: roll.c
	gcc roll.c -o roll $(CFLAGS)

noAs: noAs.c
	gcc noAs.c -o noAs $(CFLAGS)

guess: guess.c
	gcc guess.c -o guess $(CFLAGS)

clean:
	rm -f helloworld error args sum roll side_one side_two noAs guess
