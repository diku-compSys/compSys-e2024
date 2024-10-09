CC=gcc
CFLAGS=-Wall -Wextra -pedantic
PROGRAMS=forkbomb producer_consumer producer_multi_consumer

all: $(PROGRAMS)

%: %.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(PROGRAMS)