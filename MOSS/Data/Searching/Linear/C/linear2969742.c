// Linear Search
#include <stdio.h>

int linearSearch(int*, int, int);

int main(){
  int i, n, q, S[10000], T[10000], count=0;

  // 数列Tに含まれる整数の数と、その内容を入力
  scanf("%d", &n);
  for(i=0; i < n; i++){
    scanf("%d", &S[i]);
  }

  // 数列Sに含まれる整数の数と、その内容を入力
  scanf("%d", &q);
  for(i=0; i < q; i++){
    scanf("%d", &T[i]);
  }

  // 線形探索を実行
  for(i=0; i < q; i++){
    if(linearSearch(S, n, T[i]))count++;
  }

  // 結果の個数を表示
  printf("%d\n", count);

  return 0;
}

int linearSearch(int *A, int n, int key){
  int i=0;
  A[n] = key; // 配列の最後に番兵を設置

  // 配列Aのn番目には番兵であるkeyが入っているためwhileループは必ず終了する
  while(A[i] != key){
    i++;
  }
  if(i == n)return 0;
  return 1;
}

