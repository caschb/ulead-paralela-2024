#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int send_value = rank + 1;  // Each process sends its rank + 1
    int result;

    // All processes get the result of reduction (e.g., sum)
    MPI_Allreduce(&send_value, &result, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    printf("Process %d sees the sum of ranks: %d\n", rank, result);

    MPI_Finalize();
    return 0;
}
