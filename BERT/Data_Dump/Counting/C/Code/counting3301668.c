#include<stdio.h>
#define MAX 2000001

int A[MAX],B[MAX],n;

void CountingSort(){
  int i,k=10000;
  int C[10000]={};
  for(i=1;i<n+1;i++)C[A[i]]++;
  for(i=1;i<k+1;i++)C[i]=C[i]+C[i-1];
  for(i=n;i>=1;i--){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
  return;
}


int main(){
  scanf("%d",&n);
  int i;
  for(i=1;i<n+1;i++)scanf("%d",&A[i]);
  CountingSort();
  for(i=1;i<n+1;i++){
    if(i!=n)printf("%d ",B[i]);
    else printf("%d\n",B[i]);
  }
  return 0;
}

