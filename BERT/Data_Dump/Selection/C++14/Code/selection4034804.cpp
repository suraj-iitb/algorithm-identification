#include <iostream>
using namespace std;
int main() {
  int N; cin >> N;
  int A[200];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if (minj != i) {
      int temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      cnt++;
    }
  }

  for (int i = 0; i < N; i++) {
    cout << A[i];
    if (i != N-1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
  cout << cnt << endl;
}

