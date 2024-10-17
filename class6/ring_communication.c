#include <mpi.h>
#include <stdio.h>
#define MAX 1000

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  int rank, comm_size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
  MPI_Status status;
  int ring_variable = 0;
  
  while(ring_variable < MAX)
  {
    if(rank == 0)
    {
      ++ring_variable;
      MPI_Send(&ring_variable, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
      MPI_Recv(&ring_variable, 1, MPI_INT, comm_size-1, 0, MPI_COMM_WORLD, &status);
    }
    else if(rank == comm_size - 1)
    {
      MPI_Recv(&ring_variable, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &status);
      ++ring_variable;
      MPI_Send(&ring_variable, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    else if(rank % 2 == 0)
    {
      ++ring_variable;
      MPI_Send(&ring_variable, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
      MPI_Recv(&ring_variable, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &status);
    }
    else
    {
      MPI_Recv(&ring_variable, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &status);
      ++ring_variable;
      MPI_Send(&ring_variable, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
    }
  }
  if(rank == 0)
  {
    printf("%d\n", ring_variable);
  }
  MPI_Finalize();
}
