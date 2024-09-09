#include <stdio.h>
#include <omp.h>

int main() 
{
    int i;
    int shared_var = 10;  // Variable compartida
    int private_var = 20;  // Esta se volverá privada dentro de la región paralela
    int firstprivate_var = 30;  // El valor inicial de esta se copiará a cada thread.
    int lastprivate_var = 0;  // El valor final se guardará

    printf("Before parallel region:\n");
    printf("shared_var = %d, private_var = %d, firstprivate_var = %d, lastprivate_var = %d\n", 
           shared_var, private_var, firstprivate_var, lastprivate_var);

    #pragma omp parallel for shared(shared_var) private(private_var) firstprivate(firstprivate_var) lastprivate(lastprivate_var)
    for (i = 0; i < 4; i++) 
    {
        private_var = i; 
        printf("Thread %d: shared_var = %d, private_var = %d, firstprivate_var = %d\n", 
               omp_get_thread_num(), shared_var, private_var, firstprivate_var);
        
        lastprivate_var = i;
    }


    printf("\nAfter parallel region:\n");
    printf("shared_var = %d, private_var = %d, firstprivate_var = %d, lastprivate_var = %d\n", 
           shared_var, private_var, firstprivate_var, lastprivate_var);

    return 0;
}