CC=gcc
CFLAGS=-pthread -O0
PROGRAMS=hello badcount goodcount-slow goodcount-fast sharing

all: $(PROGRAMS)

%: %.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(PROGRAMS)
