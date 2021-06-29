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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void trace(int A[], int N){
    for(int i=0;i<N;i++){
        if(i>0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void bubbleSort(int A[], int N){
    int flag=1;
    int count = 0;
    while(flag){
        flag = 0;
        for(int j=N-1;j>0;j--){
            if(A[j]<A[j-1]){
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag=1;
                count++;
            }
        }

    }
    trace(A,N);
    cout << count << endl;
}

void solve() {
    int N ;
    cin >> N;
    int A[N];
    rep(i,N) cin >> A[i];

    bubbleSort(A,N);
    // cout << ans << endl;
}
signed main() {

    solve();

    return 0;
}
