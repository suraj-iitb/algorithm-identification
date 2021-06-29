#include <stdio.h>
#include <stdlib.h>

#define n_max 2000000
#define a_max 10000

int main(){
  unsigned short *A, *B;
  int C[a_max+1];
  int n, i, j;

  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */
  for(i=0;i<=a_max;i++) C[i]=0;
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }

  for(i=1;i<=a_max;i++) C[i]=C[i]+C[i-1];

  for(j=n;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);  

  return 0;
}

