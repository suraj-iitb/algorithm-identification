#include <iostream>

using namespace std;

int selectionSort(int A[], int N) {
  int swap_n = 0;
  for (int i = 0; i < N; i++) {
    int minj = i;

    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }

    int b_i = A[i];
    int swap = A[i];
    A[i] = A[minj];
    A[minj] = swap;
    if (b_i != A[i]) {
      swap_n++;
    }
  }

  return swap_n;
}

int main() {
  int N;
  cin >> N;
  int A[100];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int swap_n = selectionSort(A, N);

  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      cout << A[i] << endl;
    } else {
      cout << A[i] << " ";
    }
  }
  cout << swap_n << endl;

  return 0;
}
