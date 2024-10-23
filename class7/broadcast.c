#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    
    int rank, value;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        value = 42;  // Root process sets the value
    }

    // Broadcast value from process 0 to all processes
    MPI_Bcast(&value, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d received value %d\n", rank, value);

    MPI_Finalize();
    return 0;
}
