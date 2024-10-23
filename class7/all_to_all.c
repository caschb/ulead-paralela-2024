#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int send_values[size];  // Each process sends one value to each other process
    int recv_values[size];  // Each process receives one value from each other process

    for (int i = 0; i < size; i++) {
        send_values[i] = rank * 10 + i;
    }

    // All processes exchange data with all other processes
    MPI_Alltoall(send_values, 1, MPI_INT, recv_values, 1, MPI_INT, MPI_COMM_WORLD);

    printf("Process %d received values: ", rank);
    for (int i = 0; i < size; i++) {
        printf("%d ", recv_values[i]);
    }
    printf("\n");

    MPI_Finalize();
    return 0;
}
