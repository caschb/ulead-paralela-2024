CC=gcc-14
LIBRARY_FLAGS=-fopenmp

all: serial parallel runtime

serial: main_serial.c
	${CC} -o $@ $^

parallel: main_parallel.c
	${CC} ${LIBRARY_FLAGS} -o $@ $^

runtime: runtime-functions.c
	${CC} ${LIBRARY_FLAGS} -o $@ $^

clean:
	rm serial parallel
