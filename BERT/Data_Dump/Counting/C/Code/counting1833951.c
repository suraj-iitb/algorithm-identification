#include<stdio.h>

void CountingSort(int);

int A[2000001];
int B[2000001];
int C[10001];
int n;

int main(){

  int i,k;

  scanf("%d",&n);
  k=0;
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(A[i]>=k) k=A[i];
  }
 
  CountingSort(k);

  for(i=1;i<=n-1;i++)
    printf("%d ",B[i]);
  
    printf("%d\n",B[i]);
  
  return 0;
}

void CountingSort(int k){

  int i,j;

  for(i=0;i<=k;i++)
    C[i]=0;

  for(j=1;j<=n;j++)
    C[A[j]]++;

  for(i=1;i<=k;i++)
    C[i]+=C[i-1];

  for(j=n;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}
