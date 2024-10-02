CC=gcc-14
LINK_FLAGS=-fopenmp

all: saxpy_serial saxpy_sm

saxpy_serial.o: saxpy_serial.c
	${CC} -c $?

saxpy_serial: saxpy_serial.o
	${CC} ${LINK_FLAGS} -o $@ $?
	rm $?

saxpy_sm.o: saxpy_sm.c
	${CC} -c $?

saxpy_sm: saxpy_sm.o
	${CC} ${LINK_FLAGS} -o $@ $?
	rm $?
