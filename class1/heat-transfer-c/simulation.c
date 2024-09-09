#include "simulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void initialize_matrix(Matrix *mat, const int height, const int width) {
  mat->height = height;
  mat->width = width;
  mat->data = calloc(height * width, sizeof(double));
}

void finalize_matrix(Matrix *mat) {
  free(mat->data);
  mat->data = NULL;
}

static inline double get(const Matrix *mat, const int i, const int j) {
  return mat->data[j * mat->width + i];
}

void set(Matrix *mat, const int i, const int j, const double val) {
  mat->data[j * mat->width + i] = val;
}

void set_initial_conditions(Matrix *mat, const BoundaryConditions *conds) {
  for (int j = 0; j < mat->height; ++j) {
    set(mat, 0, j, conds->left);
    set(mat, mat->width - 1, j, conds->right);
  }

  for (int i = 0; i < mat->width; ++i) {
    set(mat, i, 0, conds->top);
    set(mat, i, mat->height - 1, conds->bottom);
  }
}

void simulate_step(const Matrix *mat, Matrix *other_matrix,
                   const double gamma) {
  for (int j = 1; j < mat->width - 1; j += 1) {
    for (int i = 1; i < mat->height - 1; i += 1) {
      double new_value = gamma * (get(mat, i + 1, j) + get(mat, i - 1, j) +
                                  get(mat, i, j + 1) + get(mat, i, j - 1) -
                                  4. * get(mat, i, j)) +
        get(mat, i, j);
      set(other_matrix, i, j, new_value);
    }
  }
}

void save_data(const Matrix *mat, int iteration) {
  struct stat sb;
  char filename_buffer[256];
  char output_directory[] = "./data";

  if (stat(output_directory, &sb) != 0 || !S_ISDIR(sb.st_mode)) {
    mkdir(output_directory, S_IRWXU);
  }

  sprintf(filename_buffer, "./data/data_%d.csv", iteration);
  FILE *fp = fopen(filename_buffer, "w");
  fprintf(fp, "x,y,u\n");
  for (int j = 0; j < mat->width; ++j) {
    for (int i = 0; i < mat->height; ++i) {
      fprintf(fp, "%d,%d,%f\n", i, j, get(mat, i, j));
    }
  }
  fclose(fp);
}
