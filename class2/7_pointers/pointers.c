#include <stdio.h>
#include <stdlib.h>

double mean(const double * numbers, const int size)
{
  double sum = 0.;
  for(int i = 0; i < size; ++i)
  {
    sum += numbers[i];
  }

  return sum / size;
}

int increment(int num)
{
  num += 1;
  return num;
}

void increment_ptr(int *num)
{
  *num += 1;
}


int main(void)
{
  int number = 0;
  int *ptr_n = &number;

  printf("number: %d, address: %p\n", number, ptr_n); // <- datos originales
  int result = increment(number);

  printf("number: %d, address: %p\n", number, ptr_n); // <- no se modifica nada

  increment_ptr(ptr_n); // increment_ptr(&number);
  printf("number: %d, address: %p\n", number, ptr_n); // <- se modifica la
                                                      //    variable
  int total_grades = 10;
  double * grades = malloc(total_grades * sizeof(double));

  printf("\n****\n");
  for(int i = 0; i < total_grades; ++i)
  {
    grades[i] = 10. - rand() % 5;
    printf("%d,%f\n", i, grades[i]);
  }
  double mean_grades = mean(grades, total_grades);
  
  printf("The mean of the grades is: %f\n", mean_grades);

  free(grades);
  
}
