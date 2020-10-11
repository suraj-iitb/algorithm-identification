#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  int *A, *B;
  int C[VMAX+1];
  int n, count=0, i, j, k=0;

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  for(i=1;i<n+1;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n+1;i++){
    if(k<A[i])k=A[i];
  }
  
  for(i=0;i<k;i++){
    C[i] = 0;
  }

  for(j=1;j<n+1;j++){
   C[A[j]]++;
  }

   for(i=1;i<VMAX+2;i++){
    C[i] += C[i-1];
  }
  
  for(i=n;i>0;i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  
  
  for(i=1;i<n+1;i++){
    if(i==n)printf("%d\n",B[i]);
    else printf("%d ",B[i]);
  }
  
  
  return 0;
}

