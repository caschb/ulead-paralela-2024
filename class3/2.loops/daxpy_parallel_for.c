#include <stdio.h>
#include <omp.h>

void daxpy(int total, double * x, double * y, double scalar)
{
  #pragma omp parallel for
  for (int i = 0; i < total; i++)
  {
    y[i] = y[i] + scalar * x[i];
  }
}

int main(void)
{
  const int N = 1000000;
  const double scalar = 2.0;
  double *x = (double*)malloc(N * sizeof(double));
  double *y = (double*)malloc(N * sizeof(double));

  for (int i = 0; i < N; i++)
  {
    x[i] = 1.0;
    y[i] = 0.0;
  }

  double start_time = omp_get_wtime();
  daxpy(N, x, y, alpha);
  double end_time = omp_get_wtime();

  printf("Execution time: %.6f seconds\n", end_time - start_time);

  free(y);
  free(x);
  return 0;
}
