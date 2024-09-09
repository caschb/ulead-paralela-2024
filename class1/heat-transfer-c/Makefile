CC=gcc-14
DEBUG_FLAGS=-g -Wall -Wextra -Waggregate-return -Wbad-function-cast -Wcast-align -Wcast-qual -Wdeclaration-after-statement -Wfloat-equal -Wformat=2 -Wmissing-declarations -Wmissing-include-dirs -Wmissing-prototypes -Wnested-externs -Wpointer-arith -Wredundant-decls -Wsequence-point -Wshadow -Wstrict-prototypes -Wswitch -Wundef -Wunreachable-code -Wunused-but-set-parameter -Wwrite-strings -fsanitize-recover=address

heat-transfer: main.c simulation.c
	${CC} $^ -o $@

heat-transfer-debug: main.c simulation.c
	${CC} ${DEBUG_FLAGS} $^ -o $@

clean:
	rm -rf heat-transfer*
