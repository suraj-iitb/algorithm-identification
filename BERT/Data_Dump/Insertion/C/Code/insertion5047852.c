#include<stdio.h>
#include<stdlib.h>

int main(){
  int *A;
  int i,j,k,length,key;
  scanf("%d",&length);
  A = (int *)malloc(length * sizeof(int));
  for(i = 0;i < length;i++){
    scanf("%d",&A[i]);
  }
  for(i = 0;i < length;i++){
    printf("%d",A[i]);
    if(i != length-1)printf(" "); 
  }
  printf("\n");
  for(i = 1;i <= length-1;i++){
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    for(k = 0;k < length;k++){
      printf("%d",A[k]);
      if(k != length-1)printf(" ");
    }
    printf("\n");
  }
  return 0;
}

