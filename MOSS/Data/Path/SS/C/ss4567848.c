#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define reps(i,a,b) for(int i=a;i<b;++i)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<typename T> inline bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T> inline bool chmin(T &a,T b){if(b<a){a=b;return 1;}return 0;}
template<typename T> vector<T> make_vec(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_vec(size_t a,Ts... ts){return vector<decltype(make_vec<T>(ts...))>(a,make_vec<T>(ts...));}
template<typename T,typename U,typename... V>
typename enable_if<is_same<T,U>::value>::type fill_v(U &u,const V... v){u=U(v...);}
template<typename T,typename U,typename... V>
typename enable_if<!is_same<T,U>::value>::type fill_v(U &u,const V... v){for(auto &e:u)fill_v<T>(e,v...);}

struct edge { int to; long long weight;};
vector<vector<edge>> G;

vector<long long> dijkstra(int s) {
    vector<long long> dist(G.size(), numeric_limits<long long>::max());
    dist[s] = 0;
    using P = pair<long long, long long>;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (edge e : G[v]) {
            if (dist[e.to] > dist[v] + e.weight) {
                dist[e.to] = dist[v] + e.weight;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, r;
    cin >> v >> e >> r;
    G.resize(v);
    rep(i, e) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].pb(edge{t, d});
    }
    auto dist = dijkstra(r);
    rep(i, v) {
        if (dist[i] > 1e18) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

