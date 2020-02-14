/**
 * @author: Shuvam Shah
 */
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0.000001

float f(float);
float abs_value(float);

float false_position(float x_l, float x_u, int iter) {
  float x_r, x_r_prev, err;
  if (f(x_l)*f(x_u) > 0) {
    printf("Not applicable here!\n");
    exit(-1);
  }
  
  x_r_prev = x_l;
  for(int i=0;i<iter;i++) {
    float F_l = f(x_l), F_u = f(x_u);
    x_r = (F_l*x_u - F_u*x_l) / (F_l - F_u);
    err = abs_value((x_r - x_r_prev) / x_r) * 100.0f;

    if (err < ERROR) {
      printf("Root: %f\n", x_r);
      return x_r;
    } else if (F_l * f(x_r) < 0) {
      x_u = x_r;
    } else {
      x_l = x_r;
    }
  }
  printf("Root: %f\n", x_r);
  return x_r;
}