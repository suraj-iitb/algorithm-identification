// Selection Sort
#include <stdio.h>

int SelectionSort(int*, int);

int main(){
int i, n, A[100], count;
  scanf("%d", &n);
  for(i=0; i < n; i++){
    scanf("%d", &A[i]);
  }
  count = SelectionSort(A, n); // 選択ソートを実行
  // 配列の内容とカウント回数を表示 //
  for(i=0; i < n; i++){
    if(i != 0)printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}

int SelectionSort(int *A, int n){
  int i, j, minj, count=0, str;
  for(i=0; i < n; i++){
    minj = i;
    for(j=i; j < n; j++){
      if(A[j] < A[minj])minj = j;
    }
    str = A[i];
    A[i] =A[minj];
    A[minj] = str;
    if(i != minj)count++;
  }
  return count;
}

