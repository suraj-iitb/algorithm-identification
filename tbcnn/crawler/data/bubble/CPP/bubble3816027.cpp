#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];

  bool flag = true;
  int i = 0;
  int counter = 0;
  while (flag) {
    flag = false;
    for (int j = N - 1; j > i; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        flag = true;
        counter++;
      }
    }
    i++;
  }

  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << counter << endl;
}

