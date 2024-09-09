CC=gcc-14
PARALLEL_FLAGS=-fopenmp

TARGETS=serial spmd spmd-2 parallel-for spmd-strided

all: ${TARGETS}

serial: pi_serial.c
	${CC} ${PARALLEL_FLAGS} -o $@ $^

spmd: pi_spmd.c
	${CC} ${PARALLEL_FLAGS} -o $@ $^

spmd-2: pi_spmd_2.c
	${CC} ${PARALLEL_FLAGS} -o $@ $^

spmd-strided: pi_strided.c
	${CC} ${PARALLEL_FLAGS} -o $@ $^

parallel-for: daxpy_parallel_for.c
	${CC} ${PARALLEL_FLAGS} -o $@ $^

clean:
	rm ${TARGETS}
