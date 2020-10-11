#include<stdio.h>
#include<stdlib.h>
#define N 2000002
int A[N],B[N],C[10001],n,i,max=0;
void CountingSort(int A[],int B[],int n);
int main(){

  scanf("%d",&n);
  for(i=1;i<=n;i++){

    scanf("%d",&A[i]);
    if(max<A[i])max=A[i];
  }

  CountingSort(A,B,max);
    
    for(i=1;i<n;i++){
      printf("%d ",B[i]);
    }

      printf("%d\n",max);
  return 0;

}
void CountingSort(int A[],int B[],int k){
  int j;

  for(i=0;i<=k;i++){
    C[i]=0;
  }

  for(j=1;j<=n;j++){
    C[A[j]]++;
  }

  for(i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }

  for(j=n;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;

  }
    return;
}
