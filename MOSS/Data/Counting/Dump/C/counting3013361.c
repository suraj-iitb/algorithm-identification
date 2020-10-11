#include<stdio.h>

void countingSort(int,int);
int A[2000001];
int B[2000001];
int main()
{
  int n,i,k;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  k=A[0];
  
  for(i=1; i<n; i++){
    if(k<A[i]) {
      k=A[i];
    }
  }
  countingSort(n,k);
  
  for(i=1; i<n; i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);

  return 0;
}

void countingSort(int n,int k){
  int i,j;
  int C[200000];
  
  for(i=0; i<=k; i++){
    C[i] = 0;
  }
  
  for(j=0; j<n; j++){
    C[A[j]]++;
  }
  
  for(i=1; i<=k; i++){
      C[i] += C[i-1];
  }
  
  for(j=n-1; j>=0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
