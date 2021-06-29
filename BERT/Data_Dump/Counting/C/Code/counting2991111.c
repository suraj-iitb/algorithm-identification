#include<stdio.h>
#define k 10000
void CountingSort(int*,int*,int);
int main(){

  int i;
  int n;

  scanf("%d",&n);
  int A[n+1],B[n+1];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  CountingSort(A,B,n);
  for(i=1;i<=n;i++){
    if(i==n) printf("%d\n",B[i]);
    else printf("%d ",B[i]);
  }
  return 0;
}

void CountingSort(int *A,int *B,int n){

  int i;
  int C[k+1];

  for(i=0;i<=k;i++) C[i]=0;
  for(i=0;i<n;i++) C[A[i]]++;
  for(i=1;i<=k;i++) C[i]+=C[i-1];
  for(i=n-1;i>=0;i--){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
}

