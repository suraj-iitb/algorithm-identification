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
    int N; cin >> N;
    vector<int> v(N);
    REP(i,N) cin >> v[i];
    int cnt = 0;
    int minj,minv;
    REP(i,N-1) {
        minj = i;
        minv = v[i];
        FOR(j,i+1,N) if(chmin(minv,v[j])) minj = j;
        if(minj != i) {
            iter_swap(v.begin()+i,v.begin()+minj);
            cnt++;
        }
    }
    REP(i,N-1) cout << v[i] << " ";
    cout << v[N-1] << endl;
    cout << cnt << endl;

}

int main() {
    solve();
    return 0;
}