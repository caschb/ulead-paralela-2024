#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  srand(0); // Usamos 0 como seed del PRNG para obtener resultados consistentes
  int num = atoi(argv[1]);
  int secret_number = rand();
  if(num == secret_number)
  {
    printf("%d == %d\n", num, secret_number);
  } else if(num > secret_number)
  {
    printf("%d > %d\n", num, secret_number);
  }
  else
  {
    printf("%d < %d\n", num, secret_number);    
  }

  
  return 0;
}
