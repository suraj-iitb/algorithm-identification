#include <iostream>

using namespace std;

void bubbleSort(int* A, int n, int& num) {
  bool flag = true;
  while (flag) {
    flag = false;
    for (int j = n - 1; j >= 1; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        flag = true;
        num++;
      }
    }
  }
}

int main () {
  int n;
  cin >> n;
  int A[101];
  int num = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  bubbleSort(A, n, num);
  for (int i = 0; i < n; i++) {
    cout << A[i];
    if (i != n - 1) {
      cout << ' ';
    }
  }
  cout << endl;
  cout << num << endl;
}
