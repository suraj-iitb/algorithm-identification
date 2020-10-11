#include <stdio.h>
#include <stdlib.h>
#define VMAX 10000

int main(){

  unsigned short *A, *B;

  int C[10001];

  int n,i,j;

  scanf("%d",&n);


  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);

  for(i=0;i<=10000;i++) C[i]=0;

  for(i=0;i<n;i++){

    scanf("%hu", &A[i+1]);
    C[A[i+1]]++;

  }

  for(i=1;i<=10001;i++){

    C[i]+=C[i-1];
  }
  
  for(j=1;j<=n;j++){
    
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
  }

  for(i=0;i<n-1;i++){

    printf("%d ",B[i+1]);
  }

  printf("%d\n",B[i+1]);

  return 0;
}

  

