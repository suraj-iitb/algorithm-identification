# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
typedef long long lint;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void solve() {
    int n;
    cin >> n;
    int A[n], C[100001]={};
    rep(i,n) {
        cin >> A[i];
        C[A[i]]++;    
    }

    for(int i=1;i<100001;i++){
        C[i] = C[i] + C[i-1];
    }

    int B[n];
    for(int i = n-1;i>=0;i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }

    rep(i,n) {
        if(i) cout << " ";
        cout << B[i];
    }
    cout << endl;
    // cout << ans << endl;
}
signed main() {

    solve();

    return 0;
}
