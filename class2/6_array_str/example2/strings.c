#include <stdio.h>
#define BUFFER_SIZE 256

int main(void)
{
  
  char mensaje_secreto[] = "!odnum aloH";
  char resultado[BUFFER_SIZE];


  int len_str = 0;
  for(len_str = 0; mensaje_secreto[len_str] != '\0'; ++len_str) {}

  printf("tamaño del string sin incluir caracter nulo: %d\n", len_str);

  for(int i = 0; i < len_str; ++i)
  {
    resultado[i] = mensaje_secreto[len_str - i - 1];
  }
  resultado[len_str+1] = '\0';

  printf("Mensaje secreto: %s\n", resultado);
  
}
