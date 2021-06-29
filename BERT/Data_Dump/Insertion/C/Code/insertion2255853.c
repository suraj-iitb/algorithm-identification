#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void insertSort(int*, int);
int main() {
    int insertNumber,i;
    int* Array;

    scanf("%d", &insertNumber);
    Array = malloc(sizeof(int) * insertNumber);
    if (Array == NULL) {
    	printf("Array is NULL.");
    }

    for(i = 0 ; i<insertNumber; i++) {
    	scanf("%d",Array + i);
    }
    for(i=0; i<insertNumber; i++) {
      if(i==insertNumber-1){
        printf("%d", *(Array+i));
      }
      else {
        printf("%d ", *(Array+i));
      }
    }
    printf("\n");
    insertSort(Array, insertNumber);
    return 0;
}

void insertSort(int* Array,int insertNumber) {
    int i,j,k,compareNumber;

    for(i = 1; i<insertNumber; i++){
    	compareNumber = *(Array + i);
	    j = i - 1;
	    while(j >= 0 && *(Array + j)>compareNumber ) {
	       *(Array+j+1) = *(Array + j);
	       j--;
	    }
	    *(Array + j +1) = compareNumber;

      for(k=0;k<insertNumber; k++) {
      	if( insertNumber-1==k ) {
  	    printf("%d",*(Array+k));
      	}
  	    else {
  	       printf("%d ", *(Array+k));
  	    }
      }
      printf("\n");
    }
}
