CFLAGS=-g -O2
LDFLAGS=-ldlt

all: dlt-diff

diff.o: diff.c
	gcc ${CFLAGS} -c -o $@ $^

dlt-diff: diff.o
	gcc ${CFLAGS} -o $@ $^ ${LDFLAGS}

clean:
	rm -f dlt-diff *~ *.o

.PHONY: all clean
