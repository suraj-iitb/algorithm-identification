#include <iostream>
using namespace std;

int main() {
  int N; cin >> N;
  int A[200];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int cnt = 0;
  int flag = 1;
  while (flag) {
    flag = 0;
    for (int i = N-1; i > 0; i--) {
      if (A[i] < A[i-1]) {
        int temp = A[i];
        A[i] = A[i-1];
        A[i-1] = temp;
        flag = 1;
        cnt++;
      }
    }
  }
  
  for (int i = 0; i < N; i++) {
    cout << A[i];
    if (i != N-1) {
      cout << " ";
    }
  }
  cout << endl << cnt << endl;
}


