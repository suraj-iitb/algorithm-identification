#include<stdio.h>
#include<stdlib.h>
#define M 2000001
#define VM 10000

int main(void){
  unsigned short *A, *B;
  int C[VM+1],n,i,j;

  scanf("%d",&n);

  A=(int *)malloc(sizeof(short)*n+1);
  B=(int *)malloc(sizeof(short)*n+1);

  for(i=0;i<VM+1;i++)
    C[i]=0;
  for(i=0;i<n;i++){
    scanf("%hu",&A[i+1]);
    C[A[i+1]]++;
  }
  for(i=1;i<VM+1;i++) C[i]=C[i]+C[i-1];
  for(j=1;j<n+1;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<n+1;i++){
    printf("%d",B[i]);
    if(i != n) printf(" ");
}
  printf("\n");
  return 0;
}
  

