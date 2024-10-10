#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int data;
  int result;
  struct Node *next;
} Node;

int es_primo(int num)
{
  if(num <= 2)
  {
    return 1;
  }
  for(int i = 2; i < num; ++i)
  {
    if(num % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

void procesar_lista(Node *node)
{
  if(node != NULL)
  {
    node->result = es_primo(node->data);
    procesar_lista(node->next);
  }
}

void imprimir_lista(Node *node)
{
  if(node != NULL)
  {
    printf("(%d,%d)\n", node->data, node->result);
    imprimir_lista(node->next);
  }
  
}

void inicializar_lista(Node **node, int start, int finish)
{
  (*node) = malloc(sizeof(Node));
  (*node)->data = start;
  (*node)->result = 0;
  if(finish != start)
  {
    inicializar_lista(&(*node)->next, start+1, finish);
  }
  else {
    (*node)->next = NULL;
  }
}  

void borrar_lista(Node **node)
{
  if(*node)
  {
    Node *next = (*node)->next;
    (*node) = NULL;
    borrar_lista(&next);
  }
}

int main()
{
  Node * node = malloc(sizeof(Node));
  int size = 100000;
  int start = 10000000;
  inicializar_lista(&node, start, start+size);
  double start_time = omp_get_wtime() - start_time;
  procesar_lista(node);
  //imprimir_lista(node);
  double final_time = omp_get_wtime() - start_time;
  printf("total time: %f\n", final_time);
  borrar_lista(&node);
  return 0;
}
