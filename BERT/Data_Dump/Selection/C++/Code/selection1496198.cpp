#include <algorithm>
#include <iostream>

using namespace std;

int selectionSort(int A[], int N) {
  int sw = 0;
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if (A[i] != A[minj]) {
      swap(A[i], A[minj]);
      sw++;
    }
  }
  return sw;
}

int main() {
  int N;
  cin >> N;

  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int sw = selectionSort(A, N);

  for (int i = 0; i < N; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;

  cout << sw << endl;

  return 0;
}
