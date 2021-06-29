// Binary Search
#include <stdio.h>

int binarySearch(int*, int, int);

int main(){
  int i, n, q, S[100000], T[50000], count=0;

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

  // 二分探索を実行
  for(i=0; i < q; i++){
    if(binarySearch(S, n, T[i]))count++;
  }

  // 結果の個数を表示
  printf("%d\n", count);

  return 0;
}

int binarySearch(int *A, int n, int key){
  int left=0, right=n, mid;
  while(left < right){
    mid = (left + right) / 2;
    if(key == A[mid]){ // 一致しているとき(見つかったとき)
      return 1;
    }
    else if(key < A[mid]){ // keyがA[mid]より小さいとき
      right = mid; // 探索範囲を前半半分にする
    }
    else{           // keyがA[mid]より大きいとき
      left = mid + 1; // 探索範囲を後半半分にする
    }
  }
  return 0;
}

