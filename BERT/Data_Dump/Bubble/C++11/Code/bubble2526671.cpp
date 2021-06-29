#include <cstdio>
#include <utility>
 
using namespace std;
 
int bubbleSort(int A[], int N) {
  int counter = 0;
  bool flag = true;
  for (int i = 0; flag; i++) {
    flag = false;
    for (int j = N - 1; j >= i + 1; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        flag = true;
        counter++;
      }
    }
  }
  return counter;
}
 
int main() {
  int N, A[100];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  int counter = bubbleSort(A, N);
 
  for (int i = 0; i < N; i++) {
    if (i != N - 1)
      printf("%d ", A[i]);
    else
      printf("%d\n", A[i]);
  }
  printf("%d\n", counter);
}
