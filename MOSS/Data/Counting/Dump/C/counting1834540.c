#include <stdio.h>

#define N 2000001
#define I 10001

void CountingSort(short*,short*,int);

int n;

int main()
{
  int i,k=0;
  short A[N],B[N];

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(k < A[i]){
      k = A[i];
    }
  }

  CountingSort(A,B,k);

  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);

  return 0;
}


void CountingSort(short a[],short b[],int k)
{
  int i,j;
  int C[I];

  for(i=0;i<=k;i++){
    C[i]=0;
  }
  
  for(j=1;j<=n;j++){
    C[a[j]]++;
  }
  
  for(i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }
  
  for(j=n;j>=1;j--){
    b[C[a[j]]] = a[j];
    C[a[j]]--;
  }
}
