#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10000

int n,i,j;

void CountingSort(short A[],short B[],int k)
{
  int C[VMAX+1];
  for(i=0;i<=k;i++) C[i]=0;

  for(j=0;j<n;j++) C[A[j]]++;

  for(i=1;i<=k;i++) C[i]=C[i]+C[i-1];

  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}

int main(){
  unsigned short *A, *B;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++) scanf("%d",&A[i]);
  CountingSort(A,B,VMAX);

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i==n){
      printf("\n");
    }else printf(" ");
  }
  return 0;
}

