#include<stdio.h>
#include<stdlib.h>

int main(){
  int n,A[1000];
  int i,j,l,key;

  scanf("%d",&n);

  if(n > 100 || n < 1){
    exit(0);
  }
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || 1000 < A[i]){
      exit(1);
    }
  }
  for(i = 0; i < n; i++){
    if(i == 0){
      printf("%d",A[i]);
      continue;
    }
    printf(" %d",A[i]);
  }
  printf("\n");

  for(i = 1; i < n; i++){
    key = A[i];
    j = i - 1;

    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    

    for(l = 0; l < n; l++){
      if(l == 0){
	printf("%d",A[l]);
	continue;
      }
      printf(" %d",A[l]);
    }
    printf("\n");
  }

  return 0;
}

