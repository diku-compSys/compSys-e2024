CFLAGS=-Wall -Wextra -pedantic

all: array 1darray sumrows

clean:
	rm -f mem args array 1darray sumrows

%: %.c
	gcc -o $@ $(CFLAGS) $^
