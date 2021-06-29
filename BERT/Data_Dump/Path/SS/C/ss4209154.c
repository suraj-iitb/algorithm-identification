#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

template<class T>
struct Dijkstra {
    const T inf = numeric_limits<T>::max() / 2 - 1;
    vector<T> dist;
    vector<int> path;
    
    Dijkstra() {}
    Dijkstra(int n) {
        graph.resize(n);
        dist.resize(n);
        prev.resize(n);
    }
    
    void add_edge(int from, int to, T cost) {
        graph[from].emplace_back(to, cost);
    }
    
    void get_distance(int from) {
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
        fill(dist.begin(), dist.end(), inf);
        fill(prev.begin(), prev.end(), -1);
        dist[from] = 0;
        pq.push(make_pair(0, from));
        while(!pq.empty()) {
            pair<T, int> p = pq.top(); pq.pop();
            if (dist[p.second] < p.first) continue;
            for (auto e : graph[p.second]) {
                if (dist[e.first] > (dist[p.second] + e.second)) {
                    dist[e.first] = dist[p.second] + e.second;
                    prev[e.first] = p.second;
                    pq.push(make_pair(dist[e.first], e.first));
                }
            }
        }
    }
    
    void get_path(int to) {
        path = vector<int>(0);
        for (; to != -1; to = prev[to]) {
            path.push_back(to);
        }
        reverse(path.begin(), path.end());
    }
    
private:
    vector<vector<pair<int, T>>> graph;
    vector<T> prev;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll v, e, r;
    cin >> v >> e >> r;
    Dijkstra<ll> dij(v);
    rep(i, e) {
        ll s, t, d;
        cin >> s >> t >> d;
        dij.add_edge(s, t, d);
    }
    dij.get_distance(r);
    rep(i, v) {
        if (dij.dist[i] == dij.inf) cout << "INF" << endl;
        else cout << dij.dist[i] << endl;
    }
    return 0;
}

