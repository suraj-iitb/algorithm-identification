#include <iostream>
using namespace std;

void insertionSort(int* A, int N) {
  int v, j;
  for (int i = 1; i < N; i ++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j --;
      A[j+1] = v;
    }
    for (int index = 0; index < N-1; index ++) {
      cout << A[index] << " ";
    }
    cout << A[N-1] << endl;
  }
}

int main() {
  int N;
  cin >> N;
  int A[N], l;
  for (int i = 0; i < N; i ++) {cin >> l; A[i] = l;}
  for (int i = 0; i < N-1; i ++) cout << A[i] << " ";
  cout << A[N-1] << endl;
  insertionSort(A, N);
}

