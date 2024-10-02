CC=gcc-14
FLAGS=-fopenmp -O3
all: matmul_serial

matmul_serial: matmul_serial.c
	${CC} ${FLAGS} -o $@ $?
