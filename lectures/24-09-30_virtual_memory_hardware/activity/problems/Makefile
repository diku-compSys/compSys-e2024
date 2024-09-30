CC=gcc
CFLAGS=-pthread -O0
PROGRAMS=leaks_indirect traceable_leaks uncertain_freeing

all: $(PROGRAMS)

%: %.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(PROGRAMS)