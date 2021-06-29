#include<iostream>
using namespace std;

const int N = 100;

int selection_sort(int n, int A[]) {
  int sw = 0, min_j;

  for (int i = 0; i < n; i++) {
    min_j = i;
    for (int j = i+1; j < n; j++) {
      if (A[j] < A[min_j]) min_j = j;
    }
    if (min_j != i) {
      sw++;
      int tmp = A[i];
      A[i] = A[min_j];
      A[min_j] = tmp;
    }
  }

  return sw;
}

int main() {
  int n;
  int A[N];

  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  int sw = selection_sort(n, A);

  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;

  return 0;
}

