#include <stdio.h>
#include <stdlib.h>
int main(){
  int i, j, k,length, key, *A;
  scanf("%d",&length);
  A = (int *)malloc(sizeof(int) * length);
  for(j=0; j<length; j++)
    scanf("%d",&A[j]);
  for(i=0; i<length; i++){
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
    }
    for(k=0; k<length; k++){
      printf("%d",A[k]);
      if(k+1 < length)
	printf(" ");
    }
      printf("\n");
  }
  return 0;
}
