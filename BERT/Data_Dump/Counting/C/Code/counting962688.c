#include<stdio.h>

#define N 2000001

int n;
int B[N];

void conting(int A[], int k){
  int C[k],i,j;
  for(i=0; i<k; i++) C[i] = 0;
  for(j=1; j<=n; j++) C[A[j]]++;
  for(i=1; i<k; i++) C[i] += C[i-1];
  for(j=n; j>=1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main(){
  int k=0,i;
  int A[N];
  scanf("%d",&n);
  for(i=1; i<=n; i++){
    scanf("%d",&A[i]);
  }
  k=A[1];
  for(i=2; i<=n; i++){
      if(k < A[i]) k = A[i];
  }
  conting(A, k+1);
  for(i=1; i<n; i++) {
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);
  return 0;
}
