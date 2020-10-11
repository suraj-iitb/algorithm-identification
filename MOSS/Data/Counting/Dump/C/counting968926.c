#include<stdio.h>
#define N 2000002

int n,A[N],B[N],C[N];

void count_sort(int A[],int k){
  long i;
  
  for(i=0;i<k;i++) C[i] = 0;
  for(i=1;i<=n;i++) C[A[i]]++;
  for(i=1;i<k;i++) C[i] = C[i] + C[i-1];
  for(i=n;i>=1;i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  for(i=1;i<n;i++) printf("%d ",B[i]);
  printf("%d\n",B[n]);
}

int main(){
  int i,k=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++) {
    scanf("%d",&A[i]);
    if(k<A[i]) k = A[i];
  }
  k = k+1;
  count_sort(A,k);
  return 0;
}
