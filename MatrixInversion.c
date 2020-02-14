/*
 * @author: Shuvam Shah
 * Lower triangular matrix using partial pivoting (more stable) and then reverse elimination using general Gauss elimination.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define EYE 1.0f
#define TOLERANCE 0.000001

void inverse(float[][SIZE], float[][SIZE], int);
void swap(float[][SIZE], int, int, int);
float abs_value(float);
void generate_eye(float[][SIZE], int);
void printMatrix(float[][SIZE], int);

int main(void) {
  int n, i, j;
  float mat[SIZE][SIZE], augmented[SIZE][SIZE], det;
  
  printf("Finding determinant using Gaussian Elimination.");
  printf("\nNote: All vectors should be linearly independent.");
  printf("\nEnter order: ");
  scanf("%d", &n);

  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      scanf("%f", &mat[i][j]);
    }
  }

  // generating identity matrix
  generate_eye(augmented, n);

  inverse(mat, augmented, n);
  printf("----------------------------------\nInverse matrix:\n");
  printMatrix(augmented, n);

  return 0;
}

void inverse(float mat[][SIZE], float augmented[][SIZE], int n) {
  float det = 1.0f, pivot1, pivot2, factor;
  int i, j, k, l, ctr=0, sign = 0, max_ind;

  /* creating lower triangular matrix */
  for(i=0;i<n-1;i++) {                // choosing pivot
    max_ind = i;
    for(l=i+1;l<n;l++) {
      if(abs_value(mat[l][i]) > abs_value(mat[max_ind][i])) {
        max_ind = l;
      }
    }

    // swap only when required
    if(i != max_ind) {
      swap(mat, i, max_ind, n);
      swap(augmented, i, max_ind, n);
      sign++;
    }
    
    pivot1 = mat[i][i];

    for(j=i+1;j<n;j++) {            // zeroizing
      pivot2 = mat[j][i];
      factor = pivot2 / pivot1;
      
      // subtraction of vectors
      for(k=0;k<n;k++) {            // subtraction of vectors
        mat[j][k] -= factor * mat[i][k];
        augmented[j][k] -= factor * augmented[i][k];
      }
    }
  }
  /* lower triangular matrix ready */

  // computing determinant by multiplication
  // of diagonal elements
  for(i=0;i<n;i++) {
    det *= mat[i][i];
  }

  if(sign%2 != 0) det *= -1;
  printf("Determinant = %.3f\n", det);

  // if determinant is zero then we are done
  if(abs_value(det) <= TOLERANCE) {
    printf("Error: Inverse can't be computed because determinant = 0.\n");
    exit(-1);
  }

  /* reverse Gauss elimination */
  // preprocessing
  for(i=0;i<n;i++) {
    pivot1 = mat[i][i];
    for(j=0;j<n;j++) {
      mat[i][j] /= pivot1;
      augmented[i][j] /= pivot1;
    }
  }

  // elimination
  for(i=n-1;i>0;i--) {
    for(j=i-1;j>=0;j--) {
      factor = mat[j][i];
      // subtraction of vectors
      for(k=0;k<n;k++) {
        mat[j][k] -= factor * mat[i][k];
        augmented[j][k] -= factor * augmented[i][k];
      }
    }
  }
}

void swap(float arr[][SIZE], int r1, int r2, int ROWLENGTH) {
	int i;
	for (i=0; i<ROWLENGTH; ++i){
  	float temp;
  	temp = arr[r2][i];
  	arr[r2][i] = arr[r1][i];
  	arr[r1][i] = temp;
	}
}

float abs_value(float n) {
  if(n >= 0) return n;
  else return (-1)*n;
}

void generate_eye(float mat[][SIZE], int order) {
  int i, j;
  for(i=0;i<order;i++) {
    for(j=0;j<order;j++) {
      if(i==j)
        mat[i][j] = EYE;
      else
        mat[i][j] = 0.0f;
    }
  }
}

void printMatrix(float mat[][SIZE], int n) {
  int i, j;
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      printf("%.3f\t", mat[i][j]);
    }
    printf("\n");
  }
}