#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10000
#define MAX 2000001

void cs(int *,int *,int );
int n,i,j,A[MAX],B[MAX],C[MAX];
int main(){
 

  scanf("%d",&n);


  for(i=1;i<=n;i++){
    scanf(" %d",&A[i]);
  }
  cs(A,B,N);

  for(i=1;i<=n-1;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);

  return 0;
}


void cs(int *A,int *B,int k){
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

