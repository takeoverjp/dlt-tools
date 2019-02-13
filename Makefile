CFLAGS=-g -O2 -I
LDFLAGS=-ldlt

all: dlt_diff

dlt_diff: diff.c
	gcc ${CFLAGS} ${LDFLAGS} -o $@ $^

clean:
	rm -f dlt_diff

.PHONY: all clean
