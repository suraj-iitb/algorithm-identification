#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10000

int main(void)
{
  unsigned short *A, *B;
  
  int C[VMAX+1];
  int n, i, j;
  scanf("%d",&n);//要素数の合計の読み取り
  
  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  
  for(i=0;i<=VMAX;i++) C[i] = 0;//Cの初期化
  
  for(i=0;i<n;i++) {
    scanf("%hu",&A[i+1]);//数値の読み取り
    C[A[i+1]]++;//数値のカウント(累積用)
  }
  
  for(i=1;i<=VMAX;i++) C[i] = C[i] + C[i-1];//累積の計算

  for(i=0;i<=VMAX;i++){
    //printf("%d ",C[i]);
    //if(C[i]==n)break;
  }
  //printf("\n");
  
  for(j=n;j>=0;j--) {
    B[C[A[j]]] = A[j];
    //printf("C[%hu]=%d ",A[j],C[A[j]]);
    C[A[j]]--;
  }
  //printf("\n");
  
  for(i=1;i<=n;i++) {
    if(i>1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  
  return 0;
}
