#include<stdio.h>
#define MAX 20000000

void CountingSort(int [],int [],int);
int Array1[MAX],Array2[MAX],k=0,n;

int main(){
  int i;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&Array1[i]);
    if(k<=Array1[i]){
      k=Array1[i];
    }
  }
  CountingSort(Array1,Array2,k);  
  for(i=1;i<=n;i++){
    if(i==n){
      printf("%d\n",Array2[i]);
    }
    else printf("%d ",Array2[i]);
  }
  return 0;
}

void CountingSort(int A[],int B[],int k){
  int i,j,C[k+1];
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=k;i++){
    C[i]+=C[i-1];
  }
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}
