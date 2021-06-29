#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

//ワーシャルフロイド法で任意2点間の最短距離を求める(負の辺があっても動作する)
//計算量 O(V^3)

template<typename T>
struct List{
    vector<vector<T>> es;
    const T INF_T;
    const int n;

    inline const vector<T> &operator [] (int k) const{
        return es[k];
    }

    inline vector<T> &operator [] (int k){
        return es[k];
    }

    List(int n) : n(n), INF_T(numeric_limits<T>::max()){
        es.resize(n);
        rep(i, n) es[i].assign(n, INF_T);
        rep(i, n) es[i][i] = 0;
    }

    void add_edge(int from, int to, T cost = 1, bool directed = false){
        es[from][to] = cost;
        if(!directed) es[to][from] = cost;
    }

    void warshall_floyd(){
        rep(k, n){
            rep(i, n){
                rep(j, n){
                    if(es[i][k] == INF_T || es[k][j] == INF_T) continue;
                    chmin(es[i][j], es[i][k]+es[k][j]);
                }
            }
        }
    }
};

int main(){
    int V, E;
    cin >> V >> E;
    List<int> G(V);
    rep(i, E){
        int u, v, c; cin >> u >> v >> c;
        G.add_edge(u, v, c, true);
    }
    G.warshall_floyd();
    rep(i, V){
        if(G[i][i] < 0){
            cout << "NEGATIVE CYCLE" << endl; return 0;
        }
    }
    rep(i, V){
        rep(j, V){
            if(G[i][j] == INT_MAX) cout << "INF";
            else cout << G[i][j];
            if(j < V-1) cout << ' ';
        }
        cout << endl;
    }
}
