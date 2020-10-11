#include <stdio.h>
#define N 10000
#define MAX 2000001

int A[MAX],B[MAX];

void CountingSort(int n,int k){
  int i,C[N],j;
  
  for(i=0;i<=k;i++){
    C[i] = 0;
  }
  for(i=0;i<n;i++){
    C[A[i]]++;
  }
  for(i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }
  for(j=n-1;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main()
{
  int i,k=0,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(A[i]>k) k = A[i];
  }
  CountingSort(n,k);
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);
  return 0;
}

