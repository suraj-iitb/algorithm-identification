#include <stdio.h>
#include <stdlib.h>
#define VMAX 100001
#define MAX 2000001
int  C[VMAX],B[MAX];
void CountingSort(int A[],int n){
  int i,j;  
  for(i=1;i<=VMAX;i++){
    C[i]=0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=VMAX;i++){
    C[i]=C[i] + C[i-1];
  }  
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<=n-1;i++){
  printf("%d ",B[i]);
  }
  printf("%d",B[n]);
  printf("\n");
}    
int main(){
  int A[MAX];
  int n, i, j;
  scanf("%d", &n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }  
  CountingSort(A,n);
  return 0;
}

