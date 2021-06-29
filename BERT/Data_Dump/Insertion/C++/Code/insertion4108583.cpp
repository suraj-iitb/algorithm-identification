#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100

void print_array(int A[], int n) {
  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << A[i];
    if (i == n - 1) cout << endl;
  }
}

int main() {
  int n;
  int A[MAX];

  cin >> n;

  // 入力
  for (int i = 0; i < n; i++) { cin >> A[i]; }

  int j, v;
  for (int i = 0; i < n; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    print_array(A, n);
  }
  return 0;
}
