#include <iostream>

using namespace std;

int bubbleSort(int A[], int N) {
  bool flag = true;
  int swapn = 0;

  while (flag) {
    flag = false;
    for (int i = N - 1; i > 0; i--) {
      if (A[i] < A[i - 1]) {
        int swap = A[i];
        A[i] = A[i - 1];
        A[i - 1] = swap;
        flag = true;
        swapn++;
      }
    }
  }

  return swapn;
}

int main() {
  int N;
  cin >> N;
  int A[100];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int swapn = bubbleSort(A, N);

  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      cout << A[i] << endl;
    } else {
      cout << A[i] << " ";
    }
  }
  cout << swapn << endl;

  return 0;
}
