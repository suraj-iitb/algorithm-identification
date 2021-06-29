// 2018/06/16
// Insertion Sort
#include <stdio.h>

void insertionSort(int*, int);

int main(){
  int i, n, A[1000];
  
  scanf("%d", &n);
  for(i=0; i < n; i++){
    scanf("%d", &A[i]);
  }

  for(i=0; i < n; i++){ // 入力した内容を表示
    if(i != 0)printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  
  insertionSort(A, n);  // 挿入ソート
  
  return 0; 
}

void insertionSort(int *A, int n){ 
  int i, j, k, v;
  
  // 挿入ソート //
  for(i=1; i < n; i++){
    v = A[i];           // 対象の配列の中身をvに保存する
    j = i-1;            // i番目の手前の配列要素を参照するためのj
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    
    // 配列の内容を表示 //
    for(k=0; k < n; k++){
      if(k != 0)printf(" ");
      printf("%d", A[k]);
    }
    printf("\n");
  }
}

