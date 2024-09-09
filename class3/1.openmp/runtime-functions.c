#include <stdio.h>
#include <omp.h>

int main(void)
{
  omp_set_num_threads(4);

#pragma omp parallel
  {
    int my_id = omp_get_thread_num();
    int total_threads = omp_get_num_threads();

    if(my_id == 0)
    {
      printf("%d, %d\n", my_id, total_threads);
    }
  }
}
