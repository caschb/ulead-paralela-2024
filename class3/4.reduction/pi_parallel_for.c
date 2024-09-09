#include <stdio.h>
#include <omp.h>

int main(void)
{
  const int num_steps = 1000000000;
  double pi = 0.;
  double sum = 0.;

  double step = 1./(double) num_steps;
  double runtime = omp_get_wtime();
#pragma omp parallel for reduction (+: sum)
  for(int i = 0; i < num_steps; ++i)
  {
    double x = (i + 0.5) * step;
    sum += 4./(1. + x * x);
  }

  runtime = omp_get_wtime() - runtime;  

  pi = step * sum;

  printf("%f, in %f\n", pi, runtime);
}
