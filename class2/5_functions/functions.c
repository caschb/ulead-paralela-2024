#include "functions.h"

long factorial(long n)
{
  long fact = 1;
  for(long i = 1; i <= n; ++i)
  {
    fact *= i;
  }
  return fact;
}

long fibo(long actual)
{
  if(actual == 0 || actual == 1)
  {
    return actual;
  }
  return fibo(actual - 1) + fibo(actual - 2);
}
