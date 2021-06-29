#include <iostream>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
  int N; cin >> N;
  int A[N];
  REP(i, N) {
    cin >> A[i];
  }
  REP(i, N) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    
    REP(k, N) {
      if (k > 0) cout << " ";
      cout << A[k];
    }
    cout << endl;
  }
}
