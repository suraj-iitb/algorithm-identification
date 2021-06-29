#include <iostream>
using namespace std;

void insertionSort(int *a, int n) {
  int v, j;
  for (int i=0; i<n; i++) {
    v = a[i];
    j = i - 1;
    while (0<=j && v<a[j]) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;

    for (int k=0; k<n; k++) {
      cout << a[k];
      if (k < n - 1) cout << " ";
    }
    cout << endl;
  }
}

int main() {
  int N, A[100];
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  insertionSort(A, N);

  return 0;
}
