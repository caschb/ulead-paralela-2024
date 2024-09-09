#include <stdio.h>
#include <omp.h>

int main(void)
{
  const int num_steps = 1000000000;
  double x = 0.;
  double pi = 0.;
  double sum = 0.;

  const double step = 1./(double) num_steps;
  double runtime = omp_get_wtime();
  for(int i = 0; i < num_steps; ++i)
  {
    x = (i + 0.5) * step;
    sum += 4./(1. + x * x);
  }

  pi = step * sum;

  runtime = omp_get_wtime() - runtime;

  printf("%f, in %f\n", pi, runtime);

  runtime = omp_get_wtime() - runtime;  
  return 0;
}
