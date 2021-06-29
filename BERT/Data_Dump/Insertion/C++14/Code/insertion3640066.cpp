#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;
#define dump(x)  cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl

#define rep(i, n) REP(i, 0, n)                              // 0, 1, ..., n-1
#define REP(i, x, n) for(int i = x; i < n; i++)             // x, x + 1, ..., n-1
#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(v) (v).begin() , (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

#define COUT(x) cout << (x) << endl

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


void insertionSort(int A[], int N) {
    for(int i = 1; i < N; ++i) {
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;

        rep(i, N) {
            if(i) cout << " ";
            cout << A[i];
        }
        cout << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A[100];
    int n; cin >> n;
    rep(i, n) cin >> A[i];
    rep(i, n) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    insertionSort(A, n);
}
