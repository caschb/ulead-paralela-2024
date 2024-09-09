#include <stdio.h>
#define BUFFER_SIZE 1000

int main(void)
{
  int small_array[] = {1, 2, 3};
  
  int big_array[BUFFER_SIZE];
  for(int i = 0; i < BUFFER_SIZE; ++i)
  {
    big_array[i] = i;
  }

  int sum = 0;
  for(int i = 0; i < BUFFER_SIZE; ++i)
  {
    sum += big_array[i];
  }

  double promedio = (double)(sum)/BUFFER_SIZE;
  printf("promedio: %f\n", promedio);
  return 0;
}
