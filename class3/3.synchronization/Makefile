CC=gcc-14
PARALLEL_FLAGS=-fopenmp

TARGETS=critical critical-bad pi-critical

all: ${TARGETS}

critical: critical.c
	${CC} ${PARALLEL_FLAGS} -o $@ $^

critical-bad: critical-bad.c
	${CC} ${PARALLEL_FLAGS} -o $@ $^

pi-critical: pi-critical.c
	${CC} ${PARALLEL_FLAGS} -o $@ $^

clean:
	rm ${TARGETS}
