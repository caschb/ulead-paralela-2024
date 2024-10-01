#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  double * data;
  int height;
  int width;
} Matrix;

inline double get_element(const Matrix *mat, int i, int j);
inline void set_element(Matrix *mat, int i, int j, double val);

double get_element(const Matrix *mat, int i, int j)
{
  int index = mat->width * i + j;
  return mat->data[index];
}

void set_element(Matrix *mat, int i, int j, double val)
{
  int index = mat->width * i + j;
  mat->data[index] = val;
}

void free_matrix(Matrix *mat)
{
  free(mat->data);
  mat->data = NULL;

  free(mat);
  mat = NULL;
}

Matrix * alloc_matrix(int height, int width)
{
  int total_elements = height * width;
  Matrix *mat = malloc(sizeof(Matrix));
  mat->height = height;
  mat->width = width;
  mat->data = malloc(sizeof(double) * total_elements);
  return mat;
}

Matrix * create_n_matrix(int height, int width, int n)
{
  int total_elements = height * width;
  Matrix *mat = alloc_matrix(height, width);
  memset(mat->data, n, total_elements);
  return mat;
}

Matrix * create_rand_matrix(int height, int width)
{
  int total_elements = height * width;
  Matrix *mat = alloc_matrix(height, width);
  
  for(int i = 0; i < total_elements; ++i)
  {
    mat->data[i] = 1. + rand()/(RAND_MAX + 1.)/10;
  }

  return mat;
}

Matrix * matmul(const Matrix *matA, const Matrix *matB)
{
  Matrix * matC = create_n_matrix(matA->height, matB->width, 0);
  for(int i = 0; i < matA->height; ++i)
  {
    for(int j = 0; j < matB->width; ++j)
    {
      double value = .0;
      for(int k = 0; k < matA->width; ++k)
      {
        value += get_element(matA, i, k) * get_element(matB, k, j);
      }
      set_element(matC, i, j, value);
    }
  }
  return matC;
}

void print_matrix(const Matrix * mat)
{
  for(int i = 0; i < mat->height; ++i)
  {
    for(int j = 0; j < mat->width; ++j)
    {
      printf("%f ", get_element(mat, i, j));
    }
    printf("\n");
  }
}

int main()
{
  Matrix * matA = create_rand_matrix(3, 4);
  Matrix * matB = create_rand_matrix(4, 1);
  Matrix * matC = matmul(matA, matB);
  print_matrix(matC);
  free_matrix(matA);
  free_matrix(matB);
  free_matrix(matC);
  return 0;
}
