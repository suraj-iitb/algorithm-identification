#include <stdio.h>
#include <stdlib.h>
#define N 10000

int main(){
  int t,i,j,C[N+1];
  unsigned short *A,*B;

  scanf("%d",&t);

  A = malloc(sizeof(short)*t+1);
  B = malloc(sizeof(short)*t+1);

 for(i=0 ; i<=N ; i++){
    C[i]=0;
  }

  for(i=1 ; i<=t ; i++){
    scanf("%d",&A[i]); 
    C[A[i]]++;
  } 

  for(i=1 ; i<=N ; i++){
    C[i] = C[i] + C[i-1];
  }

  for (j=1 ; j<=t ; j++){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=1 ; i<t ; i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[t]);
 
  return 0;
}

  
   
