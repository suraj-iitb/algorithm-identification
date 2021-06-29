// バブルソート
// O(n^2)　安定

#include <stdio.h>

#define MAX 100

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void disp(int A[], int N) {
  int i;
  for (i = 0; i < N; i++) {
    if (i) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

int bubbleSort(int A[], int N) {
    int i, cnt = 0;
    int flag = 1;

    while (flag) {
        flag = 0;
        for (i = N - 1; 0 < i; i--) {
            if (A[i] < A[i - 1]) {
	            swap(&A[i], &A[i - 1]);
	            cnt++;
	            flag = 1;
            }
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

    count = bubbleSort(A, N);

    disp(A, N);
    printf("%d\n", count);

    return 0;
}
