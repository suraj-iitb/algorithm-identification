#include <stdio.h>
#include <stdlib.h>

int main() {
  int number_of_elements;
  int i, j = 0, k;
  int key;
  int *A;
  
  scanf("%d", &number_of_elements);

  A = (int *)malloc(number_of_elements * sizeof(int));

  for(i = 0; i < number_of_elements; i++)
    scanf("%d", &A[i]);

  for(i = 1; i < number_of_elements; i++) {
    key = A[i];
    j = i - 1;
    for(k = 0; k < number_of_elements; k++){
      printf("%d", A[k]);
      if(k != number_of_elements - 1) printf(" ");
    }
    printf("\n");
    while( j >= 0 && A[j] > key) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
  }

  for(i = 0; i < number_of_elements; i++){
    printf("%d", A[i]);
    if(i != number_of_elements - 1) printf(" ");
  }
  printf("\n");

  free(A);
  
  return 0;
  
}
