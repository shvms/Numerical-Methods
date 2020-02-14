/**
 * @author: Shuvam Shah
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0.000001

float f(float);
float abs_value(float);

float bisection(float x_l, float x_u, int iter) {
  float x_m, prev_x_m, err; int i;
  if(f(x_l)*f(x_u) > 0) {
    printf("Can't use bisection method on the given interval [%f, %f].\n", x_l, x_u);
    exit(-1);
  }
  prev_x_m = x_l;
  for(i=0;i<iter;i++) {
    x_m = (x_l + x_u) / 2;

    printf("Iteration #%d:\nx_l = %f\tx_u = %f\nx_m = %f\t", i, x_l, x_u, x_m);
    if(i>0) {
      err = abs_value((x_m - prev_x_m) / x_m) * 100.0f;
      printf("Error %%: %f", err);
    }
    printf("\n-------------------------------------------\n");

    if (abs_value(f(x_m)) < ERROR) {
      return x_m;
    } else if(f(x_l)*f(x_m) < 0) {
      x_u = x_m;
    } else {
      x_l = x_m;
    }
    prev_x_m = x_m;
  }
  return x_m;
}