#include <iostream>

using namespace std;

int main() {
  int N;
  int A[100];
  
  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  
  bool flag = true;
  int cnt = 0;
  while (flag) {
    flag = false;
    for (int i=N-1; i>=1; i--) {
      if (A[i] < A[i-1]) {
        int tmp = A[i];
        A[i] = A[i-1];
        A[i-1] = tmp;
        cnt++;
        flag = true;
      }
    }
  }
  for (int i=0; i<N; i++) cout << (i != 0 ? " " : "") << A[i];
  cout << endl << cnt << endl;
  return 0;
}
