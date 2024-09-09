CC=gcc-14
PARALLEL_FLAGS=-fopenmp

TARGETS=parallel-for

all: ${TARGETS}

parallel-for: pi_parallel_for.c
	${CC} ${PARALLEL_FLAGS} -o $@ $^

clean:
	rm ${TARGETS}
