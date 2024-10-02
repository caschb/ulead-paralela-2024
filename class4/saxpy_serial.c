#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

void saxpy(float a, float * x, float * y, float * z, int elements)
{
  for(int i = 0; i < elements; ++i)
  {
    z[i] = a * x[i] + y[i];
  }
}

int main()
{
  double start, end;
  const int total_elements = 1000000;
  float a, *x, *y, *z;
  a = 10.f;

  start = omp_get_wtime();
  x = malloc(sizeof(float) * total_elements);
  y = malloc(sizeof(float) * total_elements);
  z = malloc(sizeof(float) * total_elements);

  for(int i = 0; i < total_elements; ++i)
  {
    x[i] = 1.f;
    y[i] = 2.3f;
  }
  end = omp_get_wtime() - start;
  printf("Init time: %f\n", end);

  start = omp_get_wtime();
  saxpy(a, x, y, z, total_elements);
  end = omp_get_wtime() - start;
  printf("Execution time: %f\n", end);

  free(x);
  free(y);
  free(z);
  return 0;
}
