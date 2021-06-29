#include <stdio.h>
#include <stdlib.h>

void selectionSort(int*, int);

int main() {
  int i, numberOfArray;
  int* sortArray;

  scanf("%d", &numberOfArray);
  sortArray = malloc(sizeof(int) * numberOfArray);
  for(i=0; i<numberOfArray; i++) {
    scanf("%d", sortArray+i);
  }
  selectionSort(sortArray, numberOfArray);
  return 0;
}

void selectionSort(int* sortArray, int numberOfArray) {
  int i,j,minj,storageNumber,count;

  for(i=0; i<numberOfArray; i++) {
    minj= i;
    for(j=i; j<numberOfArray; j++) {
      if( *(sortArray+j)< *(sortArray+minj) ) {
        minj= j;
      }
    }
    if( *(sortArray+i)!= *(sortArray+minj) ) {
      count++;
      storageNumber= *(sortArray+i);
      *(sortArray+i)= *(sortArray+minj);
      *(sortArray+minj)= storageNumber;
    }
  }

  for(i=0; i<numberOfArray; i++) {
    printf("%d", *(sortArray+i));
    if( i!= numberOfArray-1 ) {
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n", count);
}
