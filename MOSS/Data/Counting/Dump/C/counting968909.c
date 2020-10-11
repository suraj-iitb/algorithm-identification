//Counting Sort

#define k 10001

#include<stdio.h>
#include<stdlib.h>

int main(void){
  int n,C[k];
  int *A,*B;
  int i;

  scanf("%d",&n);

  A=(int*)malloc((n+1)*sizeof(int));
  B=(int*)malloc((n+1)*sizeof(int));

  //入力
  for(i=1;i<=n;i++) scanf("%d",&A[i]);

  //初期化
  for(i=0;i<k;i++) C[i]=0;
  
  for(i=1;i<=n;i++) C[A[i]]++;

  for(i=1;i<k;i++) C[i]+=C[i-1];

  for(i=n;i>0;i--){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }

  //出力
  printf("%d",B[1]);
  for(i=2;i<=n;i++) printf(" %d",B[i]);
  printf("\n");

  free(A);
  free(B);

  return 0;
}
