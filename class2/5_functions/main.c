#include <stdio.h>
#include "functions.h"
p
int main(void)
{
  long number = 10;
  long result = factorial(number);
  long fibo_result = fibo(number);

  printf("El factorial de %li es: %li\n", number, result);
  printf("El número de fibonacci %li es: %li\n", number, fibo_result);

  return 0;
}
