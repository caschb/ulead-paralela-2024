CC=gcc-14
PARALLEL_FLAGS=-fopenmp

TARGETS=datasharing

all: ${TARGETS}

datasharing: datasharing.c
	${CC} ${PARALLEL_FLAGS} -o $@ $^

clean:
	rm ${TARGETS}
