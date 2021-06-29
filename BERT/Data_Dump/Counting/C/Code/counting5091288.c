#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000
int main(){
  /*符号なし単精度整数を10進数として入力*/
  unsigned short *A,*B;
  int C[VMAX+1];
  int n,i,j,k;
  /*個数を入力 7つ*/
  scanf("%d",&n);
  /*short型をn+1個を確保する*/
  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);
  /*2 5 1 3 2 3 0*/
  for(i=0;i<n;i++){
    scanf("%hd",&A[i]);
  }
  k=A[0];
  /*最小値を探している*/
  for(i=0;i<n;i++){
    if(k<A[i]){
      k=A[i];
    }
  }
  /*すべてのCを0にする*/
  for(i=0;i<10001;i++){
    C[i]=0;
  }
  /*A[0]は今2,したがってC[2]は+1にする,A[1]は今5したがって、C[5]は+1にする*/
  /*C[0]=1,C[1]=1,C[2]=2,C[3]=2,C[4]=0,C[5]=1*/
  for(j=0;j<n;j++){
      C[A[j]]+=1;
    }
  /*前項の和*/
  for(i=1;i<10001;i++){
    C[i]+=C[i-1];
  }
  /*書き換える*/
  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);

  free (A);
  free (B);
  return 0;
}


