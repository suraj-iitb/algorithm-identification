#include <iostream>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPN(i, n, m) for (int i = n; i <= (int)(m); ++i)

using namespace std;

int main() {
  int N; cin >> N;
  int R[110] = {0};
  int count = 0;
  REP(i, N) cin >> R[i];
  REP(i, N) {
    int mini = i;
    REPN(j, i, N - 1) {
      if (R[j] < R[mini]) mini = j;
    }
    swap(R[i], R[mini]);
    if (i != mini) count++;
  }
  REP(i, N) {
    if (i > 0) cout << ' ';
    cout << R[i];
  }
  cout << endl;
  cout << count << endl;
}
