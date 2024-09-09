#include <stdio.h>

int main(void)
{
  // tipos enteros
  // short, int, long, long long
  // signed y unsigned
  int entero = 0;
  printf("El entero tiene un valor de: %d y un tamaño de: %lu\n", entero,\
         sizeof(int));

  // tipos de punto flotante
  // float, double, long double
  float decimal = 0.0f;
  printf("El decimal tiene un valor de: %f y un tamaño de: %lu\n", decimal,\
         sizeof(float));

  // Podemos marcar una variable como const lo que indica que una vez
  // que le asignemos un valor nunca cambiará de valor.

  const int constante = 100;

  // constante = 50; // <-- ERROR!
  
  return 0;
}
