#pragma once

typedef struct Matrix {
  double *data;
  int height;
  int width;
} Matrix;

typedef struct BoundaryConditions {
  double top;
  double bottom;
  double left;
  double right;
} BoundaryConditions;

void initialize_matrix(Matrix *mat, const int height, const int width);
void finalize_matrix(Matrix *mat);
static inline double get(const Matrix *mat, const int i, const int j);
void set(Matrix *mat, int i, int j, double val);
void set_initial_conditions(Matrix *mat, const BoundaryConditions *conds);
void simulate_step(const Matrix *mat, Matrix *other_matrix, const double gamma);
void save_data(const Matrix *mat, int iteration);
