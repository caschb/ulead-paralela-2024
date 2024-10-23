#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int send_value = rank + 1;  // Each process sends its rank + 1
    int result;

    // Reduce values from all processes to the root process (rank 0)
    MPI_Reduce(&send_value, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Sum of ranks: %d\n", result);
    }

    MPI_Finalize();
    return 0;
}
