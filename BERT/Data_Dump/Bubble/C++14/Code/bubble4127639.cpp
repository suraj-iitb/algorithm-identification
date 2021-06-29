#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

ll invNum(vector<int> &A, int l, int r){
    if(r - l == 1) return 0;
    int mid = (l + r) >> 1;
    ll res = invNum(A, l, mid) + invNum(A, mid, r);

    vector<int> L, R;
    for(int i=l;i<r;i++){
        if(i < mid) L.push_back(A[i]);
        else R.push_back(A[i]);
    }
    int N = L.size(), M = R.size();
    int cur = l, j = 0;
    for(int i=0;i<N;i++){
        while(j < M && L[i] > R[j]) A[cur++] = R[j++];
        res += j;
        A[cur++] = L[i];
    }
    for(; j<M;j++) A[cur++] = R[j];
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i,N) cin >> A[i];
    ll res = invNum(A, 0, N);
    REP(i,N){
        cout << A[i];
        if(i < N - 1) cout << " ";
    }
    cout << endl;
    cout << res << endl;
}

