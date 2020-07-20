#include<iostream>
#include <algorithm>
using namespace std;

void Bubble_Sort(int A[], int N) {
  int flag = 1, count = 0;

  while (flag) {
    flag = 0;

    for (int i = N - 1; i > 0; i--) {
        if (A[i] < A[i - 1]) {
          swap(A[i], A[i - 1]);
          flag = 1;
          count ++;
        }
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

  Bubble_Sort(A, n);

  return 0;
}

