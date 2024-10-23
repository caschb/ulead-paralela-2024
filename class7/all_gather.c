#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int send_value = rank;  // Each process sends its rank
    int recv_values[size];  // All processes will receive all values

    // Gather values from all processes at all processes
    MPI_Allgather(&send_value, 1, MPI_INT, recv_values, 1, MPI_INT, MPI_COMM_WORLD);

    printf("Process %d received values: ", rank);
    for (int i = 0; i < size; i++) {
        printf("%d ", recv_values[i]);
    }
    printf("\n");

    MPI_Finalize();
    return 0;
}
