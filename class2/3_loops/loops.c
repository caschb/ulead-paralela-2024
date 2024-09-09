#include <stdio.h>

// Leibniz formula for pi with while and for loops
int main(void)
{
  double pi = 0.0;
  double sign = -1.0;
  double denominator = 0.;
  int iterations = 1000;
  for(int i = 0; i < iterations; ++i)
  {
    sign *= -1.;
    denominator = 2. * i + 1.;
    pi += sign / denominator;
  }
  pi = 4*pi;

  printf("pi ~ %.2f\n", pi);


  int i = 0;
  sign = -1.;
  pi = 0.;
  while (i < iterations)
  {
    sign *= -1.;
    denominator = 2. * i + 1;
    pi += sign / denominator;
    i += 1;
  }
  pi = 4*pi;

  printf("pi ~ %.2f\n", pi);


  return 0;
}
