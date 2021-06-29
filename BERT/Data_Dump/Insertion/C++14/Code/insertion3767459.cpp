#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> P;
typedef long long LL;
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define IFOR(v,it) for(auto it=(v).begin();it!=(v).end();++it)
#define RIFOR(v,it) for(auto it=(v).rbegin();it!=(v).rend();++it)
#define IN_LL(v) LL v;cin>>v;
#define IN(v) int v;cin>>v;
#define OUT(v) cout<<v<<endl
#define MOD 1000000007


void insertionSort(VI& A, int N) {
  FOR(i, 1, N) {
    cout << A[0];
    FOR(i, 1, N) {
      cout << " " << A[i];
    }
    cout << endl;
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      --j;
    }
    A[j+1] = v;
  }
  cout << A[0];
  FOR(i, 1, N) {
    cout << " " << A[i];
  }
  cout << endl;
}

int main() {
  IN(N);

  VI A;
  REP(i, N) {
    IN(a);
    A.PB(a);
  }
  insertionSort(A, N);

  return 0;
}

