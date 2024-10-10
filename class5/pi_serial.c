#include <stdio.h>
#include <omp.h>

int main()
{
  const int num_steps = 1024 * 1024 * 1024;
  double x, pi, sum = 0.0;
  double start_time, end_time;

  double step = 1.0/(double) num_steps;
  start_time = omp_get_wtime();

  for(int i = 0; i < num_steps; ++i)
  {
    x = (i + .5) * step;
    sum += 4./(1. + x * x);
  }

  pi = step * sum;
  end_time = omp_get_wtime() - start_time;

  printf("pi=%f, %d steps, %f seconds", pi, num_steps, end_time);
  
  return 0;
}
