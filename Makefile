CFLAGS=-g -O2
LDFLAGS=-ldlt

all: dlt_diff

diff.o: diff.c
	gcc ${CFLAGS} -c -o $@ $^

dlt_diff: diff.o
	gcc ${CFLAGS} -o $@ $^ ${LDFLAGS}

clean:
	rm -f dlt_diff *~ *.o

.PHONY: all clean
