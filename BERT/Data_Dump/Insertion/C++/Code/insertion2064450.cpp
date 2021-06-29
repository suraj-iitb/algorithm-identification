#include <iostream>
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 100;

int main()
{
  int N, A[MAX_N];
  cin >> N;
  REP(i, N) cin >> A[i];

  REP(i, N) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    REP(j, N-1) cout << A[j] << ' ';
    cout << A[N-1] << endl;
  }

  return 0;
}
