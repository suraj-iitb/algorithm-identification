#include <bits/stdc++.h>
using namespace std;

void show(int *A, int size) {
  for(int i = 1; i <= size; ++i) {
    if(i>1) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

void insertion_sort(int *A, int size) {
  show(A, size);
  for(int j = 2; j <= size; ++j) {
    int key = A[j];
    int i = j - 1;
    while(i > 0 && A[i] > key) {
      A[i+1] = A[i];
      i = i - 1;
    }
    A[i+1] = key;
    show(A, size);
  }
}

int main() {
  int N;
  cin >> N;
  int A[N+1];
  for(int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  insertion_sort(A, N);
  return 0;
}
