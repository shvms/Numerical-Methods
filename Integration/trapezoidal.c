/**
 * @author: Shuvam Shah
 */
#include <stdio.h>

float f(float);

/*
 * a: lower limit of integration
 * b: upper limit of integration
 * n: number of segments
 */
float trapezoidal(float a, float b, int n) {
  float h = (b - a) / n;
  float area = 0.0f;
  for (int i=1;i<n;i++) {
    area += f(a + i*h);
  }
  area *= h;

  area += (h/2) * (f(a) + f(b));

  printf("Area: %f\n", area);
  return area;
}