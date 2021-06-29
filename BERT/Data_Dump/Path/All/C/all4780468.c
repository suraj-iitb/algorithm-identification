#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void Warshallfloyd(int n, V<V<ll>> &g) {
    rep(k,n)rep(i,n)rep(j,n) {
        if(g[i][k] == infll || g[k][j] == infll) continue;
        chmin(g[i][j], g[i][k] + g[k][j]);
    }
}

int main(){
    
    int v, e;
    cin >> v >> e;
    V<V<ll>> g(v,V<ll>(v,infll));
    rep(i,e) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s][t] = d;
    }

    Warshallfloyd(v,g);
    rep(i,v) {
        if(g[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    rep(i,v) {
        rep(j,v) {
            if(i == j) cout << 0;
            else if(g[i][j] == infll) cout << "INF";
            else cout << g[i][j];
            cout << (j == v-1 ? '\n' : ' ');
        }
    }
}
