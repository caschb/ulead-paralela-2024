CC=gcc-14
FLAGS=-fopenmp -O3

all: saxpy_serial saxpy_sm

saxpy_serial: saxpy_serial.c
	${CC} ${FLAGS} -o $@ $?

saxpy_sm: saxpy_sm.c
	${CC} ${FLAGS} -o $@ $?
