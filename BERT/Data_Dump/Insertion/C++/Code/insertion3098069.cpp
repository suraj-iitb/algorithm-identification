#include<iostream>
using namespace std;

void Insertion_Sort(int A[], int n) {
  for (int i = 1; i < n; i++) {
    int v = A[i];
    int j = i - 1;

    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j = j - 1;
      A[j+1] = v;
    }

    for (int k = 0; k < n; k++) {
    cout << A[k];
    if (k != n - 1) cout << " ";
    }

    cout << endl;
  }

}

int main() {
  int n, A[100];

  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  for (int i = 0; i < n; i++) {
    if (i != n -1) cout << A[i] << " ";
    else cout << A[i];
  }

  cout << endl;

  Insertion_Sort(A, n);

  return 0;
}

