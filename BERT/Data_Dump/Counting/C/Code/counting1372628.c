#include<stdio.h>
#include<stdlib.h>
#define N 2000001
   
void CountingSort(int*,int*,int);

int n;
   
main(){
   
  int i,max=0;
  int *A,*B;
  scanf("%d",&n);
  A = (int*)malloc(sizeof(int)*n);
  B = (int*)malloc(sizeof(int)*n);

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(max<A[i]) max=A[i];
  }
  CountingSort(A,B,max);
  for(i=1;i<=n-1;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
  return 0;
}
   
   
void CountingSort(int* A,int* B,int k){
   
  int i,C[N],j;
   
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
    C[A[j]]--;
  }
}
