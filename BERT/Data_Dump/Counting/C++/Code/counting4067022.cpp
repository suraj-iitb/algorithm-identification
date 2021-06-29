#include<stdio.h>
#define N 2000001

void CountingSort(int *,int *,int ,int);
int C[N];
int B[N];
int main(){
  int A[N];
  
int i,n,k=0;
  scanf("%d",&n);
for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  if(k<A[i])
    k=A[i];}
CountingSort(A,B,n,k);
  for(i=1;i<n;i++)
    printf("%d ",B[i]);
  printf("%d\n",B[n]);
  return 0;
}




void CountingSort(int *A ,int *B,int n ,int k){
  int i,j;
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=k;i++){

  C[i]=C[i]+C[i-1];
  }
 for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;}
 

 }








