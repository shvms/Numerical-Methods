#include <stdio.h>
#include <stdlib.h>

double lagrangian_interpolate(double*, double*, int, double);

int main(void) {
  int n;
  double *X, *Y, result, x_p;

  printf("Enter degree: ");
  scanf("%d", &n);

  X = (double*) malloc((n+1) * sizeof(double));
  Y = (double*) malloc((n+1) * sizeof(double));

  printf("Enter values of X & Y:");
  for(int i=0;i<=n;i++) {
    scanf("%lf %lf", &X[i], &Y[i]);
  }
  printf("Where the interpolant should be evaluated? ");
  scanf("%lf", &x_p);

  result = lagrangian_interpolate(X, Y, n, x_p);
  printf("Result: %.3f\n", result);

  return 0;
}

double lagrangian_interpolate(double* X, double* Y, int n, double x_p) {
  double result = 0.0f;
  for(int i=0;i<=n;i++) {
    double Li = 1.0f;
    for(int j=0;j<=n;j++) {
      if(j != i) {
        Li *= (x_p - X[j]) / (X[i] - X[j]);
      }
    }
    result += Li*Y[i];
  }
  return result;
}