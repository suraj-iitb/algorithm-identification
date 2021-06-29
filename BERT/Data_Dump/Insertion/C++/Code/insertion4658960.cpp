#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> v(N);
    REP(i,N) cin >> v[i];
    int j;
    REP(i,N) {
        int pick = v[i];
        j = i-1;
        while ( j >=0 && v[j] > pick) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = pick;
        REP(k,N-1)  cout << v[k] << " ";
        cout << v[N-1] << endl;
    }
}

int main() {
    solve();
    return 0;
}
