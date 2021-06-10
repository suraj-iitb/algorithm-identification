#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;

const int mod = 1e9+7;
const int INF = numeric_limits<int>::max();
const double PI = acos(-1.0);

struct edge {
    int to;
    int cost;
    edge(int t, int c): to(t), cost(c) {}
};

typedef pair<int, int> P;

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    vector<edge> G[V];

    for(int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(edge(t, d));
    }

    vector<int> d(V, INF);
    d[r] = 0;
    priority_queue<P, vector<P>, greater<P>> queue;
    queue.push(P(0, r));
    while(!queue.empty()) {

        P u = queue.top();
        queue.pop();

        int v = u.second;
        if(d[v] < u.first) continue;
        for(int i = 0; i < G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                queue.push(P(d[e.to], e.to));
            }
        }
    }

    for(int i = 0; i < V; ++i) {
        if(d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}
