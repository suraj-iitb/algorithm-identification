#include<stdio.h>
#include<stdlib.h>

int n;
void cs(int*,int*,int);

int main(){

  int i,k=0;
  int A[2000000];
  int B[2000000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(A[i]>k) k=A[i];
  }

  cs(&A[0],&B[0],k);

  for(i=0;i<n-1;i++)printf("%d ",B[i]);
  printf("%d\n",B[i]);

  return 0;
}

void cs(int* A,int* B,int k){
  int i,j;
  int *C;

  C=(int*)malloc(sizeof(int)*(k+1));
  for(i=0;i<=k;i++) C[i]=0;
  for(j=0;j<n;j++) C[A[j]]++;
  i=0;
  for(j=0;j<=k;j++){
    while(1){
      if(C[j]==0)break;
      B[i]=j;
      i++;
      C[j]--;
    }
  }
}

