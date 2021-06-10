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

//ダイクストラ法で頂点sから各点への最短距離を求める(負の辺がない場合)
//計算量 O(E*log(V))

template<typename T>
struct Weighted_Graph{
    struct edge{
        int to; T cost;
        edge(int to, T cost) : to(to), cost(cost) {}
    };

    vector<vector<edge>> es;
    vector<T> d;
    const T INF_T;
    const int n;

    Weighted_Graph(int n) : n(n), INF_T(numeric_limits<T>::max()){
        es.resize(n), d.resize(n);
    }

    void add_edge(int from, int to, T cost, bool directed = false){
        es[from].eb(to, cost);
        if(!directed) es[to].eb(from, cost);
    }

    void dijkstra(int s){
        fill(all(d), INF_T);
        using P = pair<T, int>;
        priority_queue<P, vector<P>, greater<P> > que;
        que.emplace(d[s] = 0, s);
        while(!que.empty()){
            T p; int i;
            tie(p, i) = que.top(); que.pop();
            if(p > d[i]) continue;
            for(auto &e: es[i]){
                if(chmin(d[e.to], d[i]+e.cost)) que.emplace(d[e.to], e.to);
            }
        }
    }
};

int main(){
    int V, E, s;
    cin >> V >> E >> s;
    Weighted_Graph<int> G(V);
    rep(i, E){
        int u, v, c; cin >> u >> v >> c;
        G.add_edge(u, v, c, true);
    }
    G.dijkstra(s);
    rep(i, V){
        if(G.d[i] >= inf) cout << "INF" << endl;
        else cout << G.d[i] << endl;
    }
}
