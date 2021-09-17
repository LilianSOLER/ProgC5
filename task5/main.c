#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../task3/math.c"
#include "array.c"

/*
 * Notre point d'entrée habituel.
 * Maintenant nous pouvons reconnaître que c'est une fonction, 
 * comme les autres, c'est seulement la première appelée:
 */
int main(int nargs, char** args) {

  /*
   *  ECRIVEZ VOS TESTS ICI
   */

  // Test de la fonction array_sum
  int* values = malloc(3*sizeof(int));
  values[0] = 14;
  values[1] = 5;
  values[2] = 6;
  int sum1 = array_sum(values,0,3);
  printf("array_sum(values,0,3) = %d\n", sum1);
  int sum2 = array_sum(values,1,3);
  printf("array_sum(values,1,3) = %d\n", sum2);

  // Test de la fonction array_sumf
  float* valuesf = malloc(3*sizeof(float));
  valuesf[0] = 14.0;
  valuesf[1] = 5.0;
  valuesf[2] = 6.0;
  float sum1f = array_sumf(valuesf,0,3);
  printf("array_sumf(valuesf,0,3) = %f\n", sum1f);
  float sum2f = array_sumf(valuesf,1,3);
  printf("array_sumf(valuesf,1,3) = %f\n", sum2f);

  // Test de la fonction array_average
  int average1 = array_average(values,0,3);
  printf("array_average(values,0,3) = %d\n", average1);
  int average2 = array_average(values,1,2);
  printf("array_average(values,1,3) = %d\n", average2);

  // Test de la fonction array_averagef
  float average1f = array_averagef(valuesf,0,3);
  printf("array_averagef(valuesf,0,3) = %f\n", average1f);
  float average2f = array_averagef(valuesf,1,2);
  printf("array_averagef(valuesf,1,3) = %f\n", average2f);

  // Test de la fonction array_copy
  int* array1 = malloc(3*sizeof(int));
  array1[0] = 1;
  array1[1] = 2;
  array1[2] = 3;
  int* array2 = malloc(3*sizeof(int));
  array2[0] = 4;
  array2[1] = 5;
  array2[2] = 6;
  array_copy(array2,0,array1,0,3);
  printf("array1 = %d %d %d\n", array1[0], array1[1], array1[2]);
  printf("array2 = %d %d %d\n", array2[0], array2[1], array2[2]);

  // Test de la fonction array_copyf
  float* array1f = malloc(3*sizeof(float));
  array1f[0] = 1.0;
  array1f[1] = 2.0;
  array1f[2] = 3.0;
  float* array2f = malloc(3*sizeof(float));
  array2f[0] = 4.0;
  array2f[1] = 5.0;
  array2f[2] = 6.0;
  array_copyf(array2f,0,array1f,0,3);
  printf("array1f = %f %f %f\n", array1f[0], array1f[1], array1f[2]);
  printf("array2f = %f %f %f\n", array2f[0], array2f[1], array2f[2]);

  // Test de la fonction array_sortf
  float* array3f = malloc(3*sizeof(float));
  array3f[0] = 4.0;
  array3f[1] = 3.0;
  array3f[2] = 2.0;
  array_sortf(array3f,3);
  printf("array3f = %f %f %f\n", array3f[0], array3f[1], array3f[2]);

  // Test de la fonction array_sort
  int* array3 = malloc(3*sizeof(int));
  array3[0] = 4;
  array3[1] = 3;
  array3[2] = 2;
  array_sort(array3,3);
  printf("array3 = %d %d %d\n", array3[0], array3[1], array3[2]);

  return 0; 
}
