#include <iostream>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  int N; cin >> N;
  int R[110] = {0};
  int count = 0;
  REP(i, N) cin >> R[i];
  REP(i, N) {
    for (int j = N - 1; j > i; j--) {
      if (R[j] < R[j-1]) {
        swap(R[j], R[j - 1]);
        count++;
      }
    }
  }
  REP(i, N) {
    if (i > 0) cout << ' ';
    cout << R[i];
  }
  cout << endl;
  cout << count << endl;
}
