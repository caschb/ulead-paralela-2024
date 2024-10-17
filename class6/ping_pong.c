#include <mpi.h>
#include <stdio.h>
#define MAX 1000

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  MPI_Status status;
  int i = 0;
  while(i < MAX)
  {
    if(rank == 0)
    {
      printf("ping\n");
      ++i;
      MPI_Send(&i, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
      MPI_Recv(&i, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
    }
    else
    {
      MPI_Recv(&i, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
      printf("pong\n");
      ++i;
      MPI_Send(&i, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
  }
  
  MPI_Finalize();
  return 0;
}
