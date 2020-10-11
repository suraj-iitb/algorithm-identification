#include<stdio.h>
#define ELE_MAX 10000

void CountingSort(int);

int A[2000001],B[2000001],n;
int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  CountingSort(ELE_MAX);
  for(i=1;i<=n;i++){
    if(i<n)printf("%d ",B[i]);
    else if(i==n)printf("%d\n",B[i]);
  }
  return 0;
}







void CountingSort(int k)
{
  int i,j,C[2000001];
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=0;j<n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}

