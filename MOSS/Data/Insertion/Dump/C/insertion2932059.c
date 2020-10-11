#include<stdio.h>
#include<stdlib.h>

int main(){
  int *A;
  int n, v;
  int i, j, k;
  
  scanf("%d",&n);
  A = (int *)malloc(n * sizeof(int));

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<n; i++){
    if(i==n-1)
      printf("%d",A[i]);
    else
      printf("%d ",A[i]);
  }
  printf("\n");

  for(i=1; i<n; i++){
    v = A[i];
    j = i-1;

    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }

    A[j+1] = v;

    for(k=0; k<n; k++){
      if(k==n-1)
	printf("%d",A[k]);
      else
	printf("%d ",A[k]);
    }
    printf("\n");
  }
  

  free(A);
  return 0;
}

