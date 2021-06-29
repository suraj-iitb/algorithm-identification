#include <stdio.h>

int n,k=10000, A[2000001], B[2000001];

void CountingSort(){
  int i, j, C[2000001];
  for(i=0; i<=k; i++)
    C[i] = 0;

  for(j=0; j<n; j++)
    C[A[j+1]]++;

  for(i=1; i<=k; i++)
    C[i]=C[i]+C[i-1];

  for(j=n; j>=1; j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}

int main(){
  int i;

  scanf("%d",&n);
  for(i=0; i<n; i++)
    scanf("%d",&A[i+1]);

  CountingSort();

  for(i=1; i<n; i++)
    printf("%d ",B[i]);
  printf("%d\n",B[i]);

  return 0;
}
  
    

