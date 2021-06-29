#include<iostream>
using namespace std;

int selectionSort(int A[], int N) {
  int sw = 0;
  for (int i = 0; i < N; i++) {
    int min_j = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[min_j]) {
        min_j = j;
      }
    }
    if (i != min_j) {
      swap(A[i], A[min_j]);
      sw++;
    }
  }
  return sw;
}

int main() {
  int A[100], N, sw;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  sw = selectionSort(A, N);

  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;
}

