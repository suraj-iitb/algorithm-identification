#include<stdio.h>
#define N 1000000

/*binarySearch()の擬似コード
    left = 0
    right = n
    while left < right
        mid = (left + right) / 2
        if A[mid] == key  //一致したら
            return mid（このプログラムでは1を返す）
        else if key < A[mid]
            right = mid
        else // key > A[mid]
            left = mid + 1*/

int binarySearch(int A[], int key, int n){
  int left, right, mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(A[mid] == key) return 1;
    if(key < A[mid]) right = mid;
    else if(key > A[mid]) left = mid + 1;

  }
  return 0;
}

int main(){
  int i, n, A[N], q, key, cnt = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &key);//q個の値をそれぞれ読み込み、binarySearchに渡す
    if( binarySearch(A, key, n) ) cnt++; //linearSearchで一致したものがあれば、1を返し、1が帰ってきたら、カウントを増やす
  }
  printf("%d\n", cnt);
  return 0;
}

