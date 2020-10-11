#include <stdio.h>
#define N 20000001
void CountingSort(int*,int*,int);

int n;
int A[N],B[N],C[N];
int main()
{
  int i,max;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    if(i==0){
      max = A[i];
    }
    if(A[i] > max){
      max = A[i];
    }
  }

  CountingSort(A,B,max);
  for(i=1;i<=n;i++){
    if(i==n){
      printf("%d\n",B[i]);
    }
    else printf("%d ",B[i]);
  }
}

void CountingSort(int *A,int *B,int k){
  int i,j;
  for(i=0;i<=k;i++){
    C[i] = 0;
  }
  for(j=0;j<n;j++){
    C[A[j]]++;
  }
 
  for(i=1;i<=k;i++){
    C[i] = C[i]+C[i-1];
  }
 
  for(j=n-1;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
  

