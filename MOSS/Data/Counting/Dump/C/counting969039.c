#include <stdio.h>

int A[2000001];
int B[2000001];
int C[10001];

void csort(int[],int[],int,int);

int main(){
  int k=0,n,i;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(A[i]>k){
      k=A[i];
    }
  }

  csort(A,B,k,n);
  
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i<n){
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}

void csort(int A[],int B[],int k,int  n){
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
