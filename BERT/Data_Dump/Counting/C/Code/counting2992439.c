#include <stdio.h>
#define max 2000000

void CountingS(int *,int *, int);


int n=0;
int C[max];

int main(){
  int i=0;
  scanf("%d",&n);
  int A[n+1];
  int B[n+1];
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
  }
  
  CountingS(A,B,n);
  
  for(i=1;i<n+1;i++){
    if(i==1)printf("%d",B[i]);
    else printf(" %d",B[i]);
  }
  printf("\n");

  return 0;
}

void CountingS(int *A,int *B,int k){
  int i=0;
  int j=0;
  for(i=0;i<=max;i++)C[i]=0;
  for(j=0;j<k;j++){
    C[A[j+1]]++;
  }
  for(i=1;i<=max;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=1;j<=k;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}

