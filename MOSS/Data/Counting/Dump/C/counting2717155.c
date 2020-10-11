#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(){
  int n;
  int *A,*B;
  int C[10001]={};
  int i,j;

  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&A[i]);//読み込み完了
  
  for(i=0;i<n;i++) C[A[i]]+=1;//C[k]はkが登場する回数を表す。
  for(i=1;i<=10000;i++) C[i]+=C[i-1];//C[k]はk以下の数字の個数を表す
  
  B=malloc((n+1)*sizeof(int));
  for(i=n-1;i>=0;i--){
    B[C[A[i]]]=A[i];
    C[A[i]]-=1;
  }
  
  printf("%d",B[1]);
  for(i=2;i<=n;i++) printf(" %d",B[i]);
  printf("\n");
  return 0;
}
