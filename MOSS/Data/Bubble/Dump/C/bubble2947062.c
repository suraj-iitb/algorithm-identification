// Bubble Sort
#include <stdio.h>

int BubbleSort(int*, int);

int main(){
  int i, n, A[100], count;
  scanf("%d", &n);
  for(i=0; i < n; i++){
    scanf("%d", &A[i]);
  }
  count = BubbleSort(A, n); // BubbleSortを実行
  // 配列の内容とカウント回数を表示 //
  for(i=0; i < n; i++){
    if(i != 0)printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}

int BubbleSort(int *A, int n){
  int i, str, flag, count=0;
  flag = 1; // 逆の隣接要素が存在する
  while(flag){
    flag = 0;
    for(i=n-1; i > 0; i--){
      if(A[i] < A[i-1]){ // A[i]とA[i-1]を交換する
	str = A[i];
	A[i] = A[i-1];
	A[i-1] = str;
	count++; // 交換回数を記録
	flag = 1;
      }
    }
  }
  return count; // カウント回数を返す
}

