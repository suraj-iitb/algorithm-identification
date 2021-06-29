#include<stdio.h>

int main(){
  int x, i, j, temp, count=0;

  scanf("%d",&x);
  int A[x];
  
  for(i=0; i<x; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<x-1; i++){
    for(j=x-1; j>i; j--){
      if(A[j]<A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	count++;
      }
      }
  }

  for(j=0; j<x; j++){
    printf("%d", A[j]);
    if(j<x-1) printf(" ");
  }
  
  printf("\n");
  printf("%d\n", count);

  return 0;
}

