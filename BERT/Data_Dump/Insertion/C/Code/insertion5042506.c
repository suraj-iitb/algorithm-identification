#include<stdio.h>
#include<stdlib.h>

int main(){
  int i, j, n, key; /* i,jはループに用いる変数、nは配列の要素数
                       keyはソートにおける要素の比較に用いる */
  int A[100]; /* ソート対象の配列宣言 */

  scanf("%d",&n);
  if(n<1 || n>100) exit(1);

  for(i=0; i<=n-1; i++){
    scanf("%d",&A[i]);
    if(A[i]<0 || A[i]>1000) exit(1);
  }
  
  /* これよりソート開始 */

  for(i=1; i <= n-1; i++){

    /* 出力 */
    for(j=0; j<=n-1; j++){
      printf("%d",A[j]);
      if(j != n-1) printf(" ");
    }
    printf("\n");
    
    key = A[i];
    j = i-1;

    while(j >= 0 && A[j] >key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
  }

  /* 最終結果出力 */
  for(j=0; j<=n-1; j++){
    printf("%d",A[j]);
    if(j != n-1) printf(" ");
  }
  printf("\n");
  

  return 0;
}

