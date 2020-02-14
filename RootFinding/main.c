/**
 * @author: Shuvam Shah
 */

#include <stdio.h>

// the function whose root is to be computed
float bisection(float, float, int);
float false_position(float, float, int);
float newton_raphson(float, int);

int main(void) {
  false_position(1.0f, 10.0f, 10);
  newton_raphson(1.0f, 10);
  return 0;
}

/*
 * example
 * f(x) = x^2 - 20
 */
float f(float x) {
  return (x * x) - 20;
}

/*
 * first derivative
 * computed symbolically for Newton-Raphson's method
 * f'(x) = 2*x
 */
float f_prime(float x) {
  return 2*x;
}

/*
 * f(x) = |x|
 * returns absolute value
 */
float abs_value(float x) {
  if(x < 0)
    x = (-1) * x;
  return x;
}