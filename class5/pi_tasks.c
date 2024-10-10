#include <stdio.h>
#include <omp.h>

#define MIN_BLK 1024 * 256

int pi_component(int start, int finish, double step)
{
  double x, sum1, sum2, sum = 0.0;
  if(finish - start < MIN_BLK)
  {
    for(int i = start; i < finish; ++i)
      {
        x = (i + .5) * step;
        sum += 4./(1. + x * x);
      }
  }
  else
  {
    int iblk = finish - start;
    #pragma omp task shared(sum1) 
    sum1 = pi_component(start, finish - iblk/2, step);
    #pragma omp task shared(sum2) 
    sum2 = pi_component(finish - iblk/2, finish, step);
    #pragma omp taskwait
    sum = sum1 + sum2;
  }
  return sum;
}

int main()
{
  const int num_steps = 1024 * 1024 * 512;
  double step = 1./(double) num_steps;
  
  double start_time = omp_get_wtime();
  double sum = 0.0;
  #pragma omp parallel
  {
    #pragma omp single
    sum = pi_component(0, num_steps, step);
  }
  double pi = step * sum;
  double end_time = omp_get_wtime() - start_time;

  printf("pi=%f, %d steps, %f seconds", pi, num_steps, end_time);
}
