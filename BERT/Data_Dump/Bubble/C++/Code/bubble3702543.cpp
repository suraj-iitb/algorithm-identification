#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int A[], int n) {
  int flag = -1;
  int num = 0;
  while (flag) {
    flag = 0;
    for (int j = n - 1; j > 0; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        num++;
        flag = 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << A[i];
    if (i == n - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
  cout << num << endl;
}

int main() {
  int count;
  cin >> count;
  int R[count];
  for (int i = 0; i < count; i++) cin >> R[i];

  bubbleSort(R, count);
  return 0;
}
