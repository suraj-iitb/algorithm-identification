#include<stdio.h>


int main(){
  int x, i, j, minj, count=0, tmp;
  
  scanf("%d",&x);
  int A[x];

  for(i=0; i<x; i++){
  scanf("%d", &A[i]);
  }

  for(i=0; i<x; i++){
    minj = i;
    
    for(j=i; j<x; j++){
      
      if(A[j] < A[minj]){
      minj = j;
      }
    }
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
      if(minj!=i){
	count++;
    }
  }

  for(i=0; i<x; i++){
    printf("%d", A[i]);
    if(i<x-1) printf(" ");
  }

  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

