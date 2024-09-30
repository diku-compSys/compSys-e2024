CC=gcc
CFLAGS=-pthread -O0 -g
PROGRAMS=no_leaks leaks

all: $(PROGRAMS)

%: %.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(PROGRAMS)