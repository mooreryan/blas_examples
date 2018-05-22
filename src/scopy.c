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

  x_len = SIZE * incx;
  y_len = SIZE * incy;

  sx = malloc(sizeof(float) * x_len);
  sy = malloc(sizeof(float) * y_len);

  for (i = 0; i < x_len; ++i) {
    sx[i] = (float)(i + 1) * 100;
  }

  for (i = 0, j = y_len - 1; i < y_len; ++i, --j) {
    sy[i] = (float)(j + 1);
  }

  fprintf(stdout, "\n\nAt the start\n");
  fprintf(stdout, "sx:");
  for (i = 0; i < x_len; ++i) {
    fprintf(stdout, " %.0f", sx[i]);
  }
  fprintf(stdout, "\n");

  fprintf(stdout, "sy:");
  for (i = 0; i < y_len; ++i) {
    fprintf(stdout, " %.0f", sy[i]);
  }
  fprintf(stdout, "\n");

  /* Copy x into y */
  cblas_scopy(SIZE, sx, incx, sy, incy);

  fprintf(stdout, "\n\nAfter copying\n");
  fprintf(stdout, "sx:");
  for (i = 0; i < x_len; ++i) {
    fprintf(stdout, " %.0f", sx[i]);
  }
  fprintf(stdout, "\n");

  fprintf(stdout, "sy:");
  for (i = 0; i < y_len; ++i) {
    fprintf(stdout, " %.0f", sy[i]);
  }
  fprintf(stdout, "\n");

  /* Reset sy */
  for (i = 0, j = y_len - 1; i < y_len; ++i, --j) {
    sy[i] = (float)(j + 1);
  }

  incy = 1;
  /* Copy x into y */
  cblas_scopy(SIZE, sx, incx, sy, incy);


  fprintf(stdout, "\n\nAfter copying 2nd time\n");
  fprintf(stdout, "sx:");
  for (i = 0; i < x_len; ++i) {
    fprintf(stdout, " %.0f", sx[i]);
  }
  fprintf(stdout, "\n");

  fprintf(stdout, "sy:");
  for (i = 0; i < y_len; ++i) {
    fprintf(stdout, " %.0f", sy[i]);
  }
  fprintf(stdout, "\n");



  /* Reset sy */
  for (i = 0, j = y_len - 1; i < y_len; ++i, --j) {
    sy[i] = (float)(j + 1);
  }
  /* Copy y into x.  I thought this might blow up but it doesn't.  Also doesn't give any valgrind errors. */
  cblas_scopy(SIZE, sy, incy, sx, incx);


  fprintf(stdout, "\n\nAfter copying 3rd time\n");
  fprintf(stdout, "sx:");
  for (i = 0; i < x_len; ++i) {
    fprintf(stdout, " %.0f", sx[i]);
  }
  fprintf(stdout, "\n");

  fprintf(stdout, "sy:");
  for (i = 0; i < y_len; ++i) {
    fprintf(stdout, " %.0f", sy[i]);
  }
  fprintf(stdout, "\n");




  /* Reset sx */
  for (i = 0; i < x_len; ++i) {
    sx[i] = (float)(i + 1) * 100;
  }

  incy = 2;
  cblas_scopy(SIZE, sy, incy, sx, incx);

  fprintf(stdout, "\n\nAfter copying 4th time\n");
  fprintf(stdout, "sx:");
  for (i = 0; i < x_len; ++i) {
    fprintf(stdout, " %.0f", sx[i]);
  }
  fprintf(stdout, "\n");

  fprintf(stdout, "sy:");
  for (i = 0; i < y_len; ++i) {
    fprintf(stdout, " %.0f", sy[i]);
  }
  fprintf(stdout, "\n");



  free(sx);
  free(sy);

  return 0;
}
