#include <stdio.h>

unsigned int fib(unsigned int n)
{
  unsigned int x,y;
  if (n < 2) return n;
#pragma omp task shared(x)
  x = fib(n-1);
#pragma omp task shared(y)
  y = fib(n-2);
#pragma omp taskwait
  return x + y;
}

int main()
{
  unsigned int number = 30;
  unsigned int result = 0;
#pragma omp parallel
  {
#pragma omp single
    result = fib(number);
  }
  printf("El número de Fibonacci %u es %u\n", number, result);
  return 0;
}
