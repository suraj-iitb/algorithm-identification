#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

void CountingSort(int *,int  *,int );

int main(){
  int i,k,n,C[MAX+1];

  scanf("%d",&n);

  unsigned short *A, *B;

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);


  scanf("%d",&A[0]);
  k = A[0];
  for(i=1;i<n;i++){
    scanf("%d",&A[i]);
    if(k < A[i])k = A[i];
  }

  for(i=0;i<=k;i++)
    C[i] = 0;

  for(i=0;i<n;i++)
    C[A[i]]++;

  for(i=1;i<=k;i++)
    C[i] = C[i] + C[i-1];

  for(i=n;i>=0;i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i<n)printf(" ");
  }
  printf("\n");
  return 0;
}
