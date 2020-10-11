#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
#define N 2000001
int n;

void CountingSort(short *A,short *B,int k){
  int i,j;
  int C[MAX+1];

  for(i=0;i<=k;i++){
    C[i]=0;
  }

  for(j=1;j<=n;j++){
    C[A[j]]++;
  }

  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }

  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<=n;i++){
    printf("%hu",B[i]);
    if(i<n)
      printf(" ");
  }

}


int main(){

  int i;
  unsigned short *A,*B;

  scanf("%d",&n);
  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++){
    scanf("%hu",&A[i+1]);
  }

  CountingSort(A,B,MAX);
  printf("\n");

  return 0;
}
