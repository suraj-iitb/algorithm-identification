#include <iostream>
using namespace std;

void trace(int A[], int n) {
  for(int i = 0; i < n ; i++) {
    if (0 < i) { cout << " "; }
    cout << A[i];
  }
  cout << endl;
}

void insertionSort(int A[], int n) {
  for(int i = 1; i < n ; i++) {
    int v, j;
    v = A[i];
    j = i - 1;
    while ( j>= 0 && A[j]>v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    trace(A,n);
  }
}

int main() {
  int n;
  int A[1000];

  cin >> n;
  for (int i = 0; i < n ; i++) cin >> A[i];

  trace(A, n);
  insertionSort(A, n);

  return 0;
}
