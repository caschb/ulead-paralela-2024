CC=gcc

all: matmul_serial

matmul_serial.o: matmul_serial.c
	${CC} -c $?

matmul_serial: matmul_serial.o
	${CC} $? -o $@
