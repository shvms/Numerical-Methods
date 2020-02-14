/**
 * @author: Shuvam Shah
 */
#include <stdio.h>

float f(float);

/*
 * a: lower limit of integration
 * b: upper limit of integration
 * n: number of segments (must be even)
 */
float simpsons(float a, float b, int n) {
  float area=0.0f, h = (b-a)/n;

  for(int i=1;i<n;i++) {
    if(i%2 == 0)
      area += 2 * f(a + i*h);
    else
      area += 4 * f(a + i*h);
  }

  area += f(a) + f(b);
  area *= (h/3);

  printf("Area: %f\n", area);
  return area;
}