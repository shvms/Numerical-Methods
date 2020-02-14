#include <stdio.h>

float trapezoidal(float, float, int);
float simpsons(float, float, int);
float f(float);

int main(void) {
  simpsons(0.0f, 2.0f, 10);
  return 0;
}

float f(float x) {
  return (x - x*x*x + 8);
}