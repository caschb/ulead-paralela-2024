#include <stdio.h>

unsigned int fib(unsigned int n)
{
  unsigned int x,y;
  if (n < 2) return n;
  x = fib(n-1);
  y = fib(n-2);
  return x + y;
}

int main()
{
  unsigned int number = 30;
  unsigned int result = fib(number);
  printf("El número de Fibonacci %u es %u\n", number, result);
  return 0;
}
