#include<stdio.h>
#define nMAX 100000 /*数列Sの最大の要素数*/
#define qMAX 50000   /*数列Tの最大の要素数*/

int main (){

  int count = 0, left, right, mid, i, j, n, q, S[nMAX], T[qMAX];

  /*S行列の読み込み*/
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &S[i]);

  /*T行列の読み込み*/
  scanf("%d", &q);
  for(i = 0; i < q; i++)
    scanf("%d", &T[i]);

  /*二分探索*/
  for(i = 0; i < q; i++){
     left = 0;
     right = n;
     while(left < right){
       mid = (left + right) / 2;
       if(S[mid] == T[i]){
         count++;
         break;
       }
       else if(T[i] < S[mid])
         right = mid;
       else
         left = mid + 1;
     }
  }

  /*２つの行列に共通する数の総数の表示*/
  printf("%d\n", count);

  return 0;
}

