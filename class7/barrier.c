#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("Process %d before barrier\n", rank);
    
    // Synchronize all processes
    MPI_Barrier(MPI_COMM_WORLD);

    printf("Process %d after barrier\n", rank);

    MPI_Finalize();
    return 0;
}
