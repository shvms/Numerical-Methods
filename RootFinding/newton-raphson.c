/**
 * @author: Shuvam Shah
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0.000001

float f(float);
float f_prime(float);
float abs_value(float);

float newton_raphson(float x_i, int iter) {
  float x_ip1, error;
  for(int i=0;i<iter;i++) {
    x_ip1 = x_i - f(x_i) / f_prime(x_i);
    error = abs_value((x_ip1 - x_i) / x_ip1) * 100.0f;
    if (error < ERROR) {
      printf("Root: %f\n", x_ip1);
      return x_ip1;
    }
    x_i = x_ip1;
  }

  printf("Root: %f\n", x_ip1);
  return x_ip1;
}