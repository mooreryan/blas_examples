#include <cblas.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int main(int argc, char *argv[])
{
  int i = 0;
  int j = 0;

  int x_len = 0;
  int y_len = 0;

  float *sx, *sy;

  int incx = 1;
  int incy = 2;

  double dot_product = 0.0;

  x_len = SIZE * incx;
  y_len = SIZE * incy;

  sx = malloc(sizeof(float) * x_len);
  sy = malloc(sizeof(float) * y_len);

  for (i = 0; i < x_len; ++i) {
    sx[i] = (float)i;
  }

  for (i = 0, j = y_len - 1; i < y_len; ++i, --j) {
    sy[i] = (float)j;
  }

  fprintf(stdout, "\n\nAt the start\n");
  fprintf(stdout, "sx:");
  for (i = 0; i < x_len; ++i) {
    fprintf(stdout, " %.2f", sx[i]);
  }
  fprintf(stdout, "\n");

  fprintf(stdout, "sy:");
  for (i = 0; i < y_len; ++i) {
    fprintf(stdout, " %.2f", sy[i]);
  }
  fprintf(stdout, "\n");

  /* Copy x into y */
  cblas_scopy(SIZE, sx, incx, sy, incy);

  fprintf(stdout, "\n\nAfter copying\n");
  fprintf(stdout, "sx:");
  for (i = 0; i < x_len; ++i) {
    fprintf(stdout, " %.2f", sx[i]);
  }
  fprintf(stdout, "\n");

  fprintf(stdout, "sy:");
  for (i = 0; i < y_len; ++i) {
    fprintf(stdout, " %.2f", sy[i]);
  }
  fprintf(stdout, "\n");


  free(sx);
  free(sy);

  return 0;
}
