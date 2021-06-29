#include <iostream>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP1(i, n) for (int i = 1; i <= (int)(n); ++i)

using namespace std;

void print(int N, int a[110]) {
  REP(i, N) {
    if (i > 0) cout << ' ';
    cout << a[i];
  }
  cout << endl;
}

int main() {
  int N; cin >> N;
  int A[110] = {0};
  REP(i, N) {
    cin >> A[i];
  }
  REP1(i, N - 1) {
    print(N, A);
    int key = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
  }
  print(N, A);
}

