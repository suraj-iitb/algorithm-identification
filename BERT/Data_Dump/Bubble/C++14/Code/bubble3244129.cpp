#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int A[], int n) {
  bool flag = true;
  int count = 0;
  while (flag) {
    flag = false;
    for (int i = n - 1; 0 < i; i--) {
      if (A[i] < A[i - 1]) {
        swap(A[i], A[i - 1]);
        count++;
        flag = true;
      }
    }
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int count;
  count = bubbleSort(A, n);
  for (int i = 0; i < n; i++) {
    if (i) {
      cout << ' ';
    }
    cout << A[i];
  }
  cout << endl;
  cout << count << endl;
}

