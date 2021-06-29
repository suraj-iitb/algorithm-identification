#include<iostream>
#include <algorithm>
using namespace std;

void Select_Sort(int A[], int N) {
  int count = 0;

  for (int i = 0; i < N; i++) {
    int minj = i;

    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }

    if (A[i] != A[minj]) {
      swap(A[i], A[minj]);
      count++;
    }
  }

  for (int k = 0; k < N; k++) {
    cout << A[k];
    if (k != N - 1) cout << " ";
  }

  cout << endl << count << endl;

}

int main() {
  int n, A[100];

  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  Select_Sort(A, n);

  return 0;
}

