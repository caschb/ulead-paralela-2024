#include "simulation.h"
#include <stdlib.h>

int main(void) {
  const int plate_length = 50;
  const int max_iter_time = 750;

  const double alpha = 2.;
  const double delta_x = 1.;
  const double delta_t = (delta_x * delta_x) / (4. * alpha);
  const double gamma = (alpha * delta_t) / (delta_x * delta_x);

  Matrix *grid = malloc(sizeof(Matrix));
  Matrix *other_grid = malloc(sizeof(Matrix));
  initialize_matrix(grid, plate_length, plate_length);
  initialize_matrix(other_grid, plate_length, plate_length);

  BoundaryConditions conds = {100.0, 100.0, 100.0, 100.};
  set_initial_conditions(grid, &conds);
  set_initial_conditions(other_grid, &conds);

  save_data(grid, 0);
  for (int k = 1; k < max_iter_time; ++k) {
    simulate_step(grid, other_grid, gamma);
    Matrix *aux = grid;
    grid = other_grid;
    other_grid = aux;
    save_data(grid, k);
  }
  finalize_matrix(grid);
  finalize_matrix(other_grid);
  free(grid);
  free(other_grid);
  return 0;
}
