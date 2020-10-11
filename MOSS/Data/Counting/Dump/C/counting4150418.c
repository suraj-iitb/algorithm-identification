#include <stdio.h>
#include <stdlib.h>
#define VMAX 10000


void CountingSort(unsigned short *A,unsigned short * B,int  n){//入力用・ソート後の配列
  int i;
  int C[VMAX+1]={0}; //メモ
  
  /* C[i] に i の出現数を記録する */
  for (i = 0;i< n;i++)C[A[i]]++;

  /* C[i] に i 以下の数の出現数を記録する*/
  for (i = 1;i<VMAX+1;i++){
    C[i] += C[i-1];
  }
  
  for (i = n-1;i>=0;i--){//後ろから選んでいるので安全
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}


int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);//入力用
  B = malloc(sizeof(short)*n+1);//ソート後

  for(i=0;i<n;i++)scanf("%hd",&A[i]);
  
  CountingSort(A, B, n);//入力用・ソート後の配列
  
  for(i=1;i<=n;i++){
    if(i!=1)printf(" ");
    printf("%hd",B[i]);
  }
  printf("\n");
 
  return 0;
}

