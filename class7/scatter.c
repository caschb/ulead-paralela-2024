#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int send_values[size];  // Only the root process will send values
    if (rank == 0) {
        for (int i = 0; i < size; i++) {
            send_values[i] = i * 10;
        }
    }

    int recv_value;  // Each process will receive one value

    // Scatter values from root process (rank 0) to all processes
    MPI_Scatter(send_values, 1, MPI_INT, &recv_value, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d received value %d\n", rank, recv_value);

    MPI_Finalize();
    return 0;
}
