#include <iostream>

using namespace std;

void insertionSort(int A[], int N) {
  for (int i = 1; i < N; i++) {
    for (int i = 0; i < N; i++) {
      if (i == N - 1) {
        cout << A[i] << endl;
      } else {
        cout << A[i] << " ";
      }
    }

    int v = A[i];
    int j = i - 1;

    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
  }

  for (int i = 0; i < N; i++) {
      if (i == N - 1) {
        cout << A[i] << endl;
      } else {
        cout << A[i] << " ";
      }
    }
}

int main() {
  int N;
  cin >> N;
  int A[100];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  insertionSort(A, N);
  return 0;
}
