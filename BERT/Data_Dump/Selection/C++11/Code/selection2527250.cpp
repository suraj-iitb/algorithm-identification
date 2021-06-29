#include <algorithm>
#include <cstdio>

using namespace std;

void selectionSort(int A[], int N) {
  int counter = 0;
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) minj = j;
    }
    swap(A[i], A[minj]);
    if (i != minj) counter++;
  }
  for (int i = 0; i < N; i++) {
    printf("%d", A[i]);
    if (i != N - 1) printf(" ");
  }
  printf("\n");
  printf("%d\n", counter);
}
int main() {
  int N, A[100];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  selectionSort(A, N);
}
