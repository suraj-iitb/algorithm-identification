// Quick Sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000
#define INFTY 1000000000

typedef struct{
  char suit;
  int value;
}card;

void QuickSort(card*, int, int);
int Partition(card*, int, int);
void merge(card*, int, int, int);
void mergeSort(card*, int, int);

int main(){
  int i, n;
  card A[MAX], B[MAX];

  scanf("%d", &n);
  for(i=0; i < n; i++){
    scanf("%s %d", &A[i].suit, &A[i].value);
    B[i] = A[i];
  }
  
  QuickSort(A, 0, n-1); // クイックソートを実行
  mergeSort(B, 0, n); // 安定かどうかの確認のため安定なソートであるマージソートを使う

  for(i=0; i < n; i++){
    if(A[i].suit != B[i].suit){
      printf("Not stable\n");
      break;
    }
  }
  if(i == n)printf("Stable\n");
  
  for(i=0; i < n; i++){
    printf("%c %d\n", A[i].suit, A[i].value);  
  }
  
  return 0;
}

void QuickSort(card *A, int p, int r){
  int q;
  if(p < r){
    q = Partition(A, p, r);
    QuickSort(A, p, q-1);
    QuickSort(A, q+1, r);
  }
}

int Partition(card *A, int p, int r){
  int i, j;
  card swap;

  // 配列の要素0からiまでは基準A[r]より小さい値、
  // 要素i+1からr-1までは基準A[r]より大きい値を格納していく
  i = p-1;
  for(j=p; j < r; j++){ // 基準A[r]の手前の要素までループ
    if(A[j].value <= A[r].value){
      i++;
      swap=A[i];  A[i]=A[j];  A[j]=swap; // A[i]とA[j]を交換
    }
  }
  swap=A[i+1];  A[i+1]=A[r];  A[r]=swap; // 最後にA[i+1]A[r]を交換
  return i+1; // パーティションの基準となる要素を返す
}

void merge(card *A, int left, int mid, int right){
  int i, j, k, n1, n2;
  card L[MAX], R[MAX];
  n1 = mid - left;
  n2 = right - mid;
  for(i=0; i < n1; i++){
    L[i] = A[left + i];
  }
  for(i=0; i < n2; i++){
    R[i] = A[mid + i];
  }
  L[n1].value = INFTY; // 番兵を設置
  R[n2].value = INFTY; // 番兵を設置
  i = 0;
  j = 0;
  for(k=left; k < right; k++){
    if(L[i].value <= R[j].value){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(card *A, int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

