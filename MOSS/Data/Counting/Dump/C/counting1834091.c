#include <stdio.h>
#include <stdlib.h>
#define N 2000001
#define AMAX 10005

int main(){
  int i,j,num,*A,*B,C[AMAX];
  scanf("%d",&num);

  A = (int *)malloc(sizeof(int)*num+1);
  B = (int *)malloc(sizeof(int)*num+1);
 
  for(i=0; i<AMAX; i++) C[i] = 0;
  for(j=1; j<=num; j++){
    scanf("%d",&A[j]);
    C[A[j]]++;
  }

  for(i=0; i<AMAX; i++) C[i] = C[i] + C[i-1];

  for(j=num; j>0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=1; i<=num; i++){
    printf("%d",B[i]);
    if(i!=num) printf(" ");
  }
    printf("\n");
 

  return 0;

}
