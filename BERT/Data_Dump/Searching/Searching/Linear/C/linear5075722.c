#include<stdio.h>
#define nMAX 10000 /*数列Sの最大の要素数*/
#define qMAX 500   /*数列Tの最大の要素数*/

int main (){

  int count = 0, i, j, n, q, S[nMAX], T[qMAX];

  /*S行列の読み込み*/
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &S[i]);

  /*T行列の読み込み*/
  scanf("%d", &q);
  for(i = 0; i < q; i++)
    scanf("%d", &T[i]);

  /*番兵付き線形探索*/
  for(i = 0; i < q; i++){
    S[n] = T[i];
    j = 0;
    while(1){
      if(j == n)break; 
      else if(S[j] == S[n]){
        count++;
        break;
      }
      else j++;
    }
  }
  /*２つの行列に共通する数の総数の表示*/
  printf("%d\n", count);

  return 0;
} 

