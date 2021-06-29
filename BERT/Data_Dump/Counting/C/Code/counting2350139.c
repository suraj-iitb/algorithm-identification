#include <stdio.h>

void CountingSort(int *,int *,int);

int A[2000001];
int B[2000001];
int n;

int main(){

  int i,max=0;
  
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }

  CountingSort(A,B,10000);

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i<n) printf(" ");
  }
  printf("\n");

  return 0;
  
}

void CountingSort(int A[],int B[],int k){

  int C[k+1];
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

  for(j=n;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}
