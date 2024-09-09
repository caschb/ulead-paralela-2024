#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 4

int main(void)
{
  const int num_steps = 1000000000;
  int num_threads = -1;
  double pi = 0.;
  double sums[NUM_THREADS];

  const double step = 1./(double) num_steps;
  double runtime = omp_get_wtime();

  omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
  {
    int thread_id = omp_get_thread_num();
    int total_threads = omp_get_num_threads();
    double x = .0;
    if(thread_id == 0)
    {
      num_threads = total_threads;
    }
    sums[thread_id] = 0.;
    for(int i = thread_id; i < num_steps; i+=total_threads)
    {
      x = (i + 0.5) * step;
      sums[thread_id] += 4./(1. + x * x);
    }
  }

  for(int i = 0; i < num_threads; ++i)
  {
    pi += step * sums[i];
  }

  runtime = omp_get_wtime() - runtime;  

  printf("%f, in %f\n", pi, runtime);
}
