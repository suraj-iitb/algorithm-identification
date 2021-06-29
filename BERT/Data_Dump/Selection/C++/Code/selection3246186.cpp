#include <iostream>

using namespace std;

int main() {
  int N;
  int A[100];
  
  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  
  int cnt = 0;
  for (int i=0; i<N; i++) {
    int minj = i;
    for (int j=i; j<N; j++) if (A[j] < A[minj]) minj = j;
    if (i != minj) {
        int tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        cnt++;
      }
  }
  
  for (int k=0; k<N; k++) cout << (k != 0 ? " " : "") << A[k];
  cout << endl << cnt << endl;
  
  return 0;
}

