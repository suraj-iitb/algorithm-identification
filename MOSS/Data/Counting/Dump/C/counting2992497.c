#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=1;i<=n;i++){
    scanf("%hd",&A[i]);
  }

  for(i=0;i<VMAX+1;i++){
    C[i]=0;
  }
  
  for(i=1;i<=n;i++)C[A[i]]++;


  //for(i=0;i<=n;i++)printf("%d\n",C[i]);
  j=A[1];
  for(i=1;i<=n;i++){
    if(A[i+1]>j)j=A[i+1];
  }
  // printf("%d\n",j);
  for(i=1;i<=j;i++)C[i]=C[i]+C[i-1];



  for(i=n;i>0;i--){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
  for(i=1;i<n;i++)printf("%d ",B[i]);
  printf("%d\n",B[n]);
  return 0;
}

