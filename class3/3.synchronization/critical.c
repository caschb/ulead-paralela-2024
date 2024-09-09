#include <stdio.h>
#include <omp.h>

int main(void)
{
  const int total_steps = 1000;
  int sum = 0;
#pragma omp parallel for
  for(int i = 1; i <= total_steps; ++i)
  {
//#pragma omp atomic
#pragma omp critical
    {
      sum += i;
    }
  }
  printf("%d\n", sum);
}
