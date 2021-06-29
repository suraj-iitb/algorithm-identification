#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll int64_t
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int A[2020202],B[2020202],C[10101];
int n;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    REP(i,n) cin>>A[i+1];
    REP(i,10101) C[i]=0;

    for(int j=1;j<=n;j++) C[A[j]]++;
    for(int i=1;i<10101;i++) C[i]+=C[i-1];
    for(int j=n;j>=1;j--){
        B[C[A[j]]]=A[j];
        C[A[j]]--;
    }
    REP(i,n){
        if(i) cout<<" ";
        cout<<B[i+1];
    }
    cout<<endl;
}
