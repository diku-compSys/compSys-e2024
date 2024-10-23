CC=gcc
CFLAGS=-pthread
PROGRAMS=echo_client echo_server

all: $(PROGRAMS)

%: %.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(PROGRAMS)