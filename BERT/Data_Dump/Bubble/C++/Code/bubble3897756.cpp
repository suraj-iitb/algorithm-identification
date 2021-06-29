#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int A[101], n, cnt = 0;

void print () {
  for (int i = 0; i < n; i++)
    if (i == n - 1)
      cout << A[i] << endl;
    else
      cout << A[i] << " ";
}

void BubbleSort () {
  bool flag = true;

  while (flag) {
    flag = false;

    for (int j = n - 1; j >= 1; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        flag = true;
        cnt++;
      }
    }
  }
}

int main () {
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> A[i];

  for (int i = 0; i < n; i++)
    BubbleSort();

  print();
  cout << cnt << endl;

  return 0;
}

