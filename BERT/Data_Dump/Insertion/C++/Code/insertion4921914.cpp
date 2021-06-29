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

void insertionSort(int A[], int N){
    for(int i=1;i<N;i++){
        int v = A[i];
        int j = i-1;
        while(j >=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A,N);
    }
}

void solve() {
    int N;
    cin >> N;
    int A[N];

    rep(i,N) cin >> A[i];

    trace(A,N);
    insertionSort(A,N); 
}
signed main() {

    solve();

    return 0;
}
