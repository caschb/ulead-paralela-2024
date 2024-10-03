#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
void saxpy(float a, float * x, float * y, const int elements, const int chunk_size)
{
#pragma omp parallel for schedule(static, chunk_size) default(none) shared(a, x, y, chunk_size, elements)
  for(int i = 0; i < elements; ++i)
  {
    y[i] = a * x[i] + y[i];
  }
}
int main(int argc, char ** argv)
{
  double start, end;
  int total_elements = atoi(argv[1]);
  int chunk_size = atoi(argv[2]);
  float a, *x, *y;
  a = 10.f;
  start = omp_get_wtime();
  x = malloc(sizeof(float) * total_elements);
  y = malloc(sizeof(float) * total_elements);

#pragma omp parallel for schedule(static, chunk_size) default(none) shared(total_elements, x, y, chunk_size)
  for(int i = 0; i < total_elements; ++i)
  {
    x[i] = 1.f;
    y[i] = 2.3f;
  }
  end = omp_get_wtime() - start;
  printf("Init time: %f\n", end);
  start = omp_get_wtime();
  saxpy(a, x, y, total_elements, chunk_size);
  end = omp_get_wtime() - start;
  printf("Execution time: %f\n", end);
  free(x);
  free(y);
  return 0;
}
