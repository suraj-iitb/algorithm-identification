#include <iostream>
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 100;

int main()
{
  int N, A[MAX_N], flag, cnt;
  cin >> N;
  REP(i, N) cin >> A[i];

  flag = 1;
  cnt = 0;
  while (flag) {
    flag = 0;
    REP(i, N) {
      if (i == 0) continue;
      if (A[N-i] < A[N-i-1]) {
        swap(A[N-i], A[N-i-1]);
        cnt++;
        flag = 1; 
      }
    }
  }
  REP(i, N-1) cout << A[i] << ' ';
  cout << A[N-1] << endl;
  cout << cnt << endl;

  return 0;
}
