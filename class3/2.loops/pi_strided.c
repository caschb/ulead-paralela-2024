#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 4
#define PAD 16 // 128 B cacheline size on M{1,2,3} macbooks.
//#define PAD 8 // 64 B cacheline size on most x64 processors.

int main(void)
{
  const int num_steps = 1000000000;
  int num_threads = -1;
  double x = 0.;
  double pi = 0.;
  double sums[NUM_THREADS][PAD];

  const double step = 1./(double) num_steps;
  double runtime = omp_get_wtime();

  omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
  {
    int thread_id = omp_get_thread_num();
    int total_threads = omp_get_num_threads();
    if(thread_id == 0)
    {
      num_threads = total_threads;
    }
    sums[thread_id][0] = 0.;
    for(int i = thread_id; i < num_steps; i+=total_threads)
    {
      x = (i + 0.5) * step;
      sums[thread_id][0] += 4./(1. + x * x);
    }
  }

  for(int i = 0; i < num_threads; ++i)
  {
    pi += step * sums[i][0];
  }

  runtime = omp_get_wtime() - runtime;  

  printf("%f, in %f\n", pi, runtime);
}
