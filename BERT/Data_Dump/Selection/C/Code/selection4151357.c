// 選択ソート
// O(n^2) 安定でない

#include <stdio.h>

#define MAX 100

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void disp(int A[], int N){
    int i;

    // 表示
    for(i = 0; i < N; i++){
        if (i == 0) printf("%d", A[i]);
        else printf(" %d", A[i]);
    }
    // 改行を出力
    printf("\n");
}

int selectionSort(int A[], int N) {
    int i, j, tmp, cnt = 0;
    int minj;

    for (i = 0; i < N; i++) {
        minj = i;
        for (j = i; j < N; j++) {
            if (A[j] < A[minj]) {
	            minj = j;
            }
        }

        if (i != minj) {
            swap(&A[i], &A[minj]);
            cnt++;
        }
    }
    return cnt;
}

int main(){
  int i, N;
  int A[MAX];
  int count;

  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  count = selectionSort(A, N);

  disp(A, N);

  printf("%d\n", count);


  return 0;
}
