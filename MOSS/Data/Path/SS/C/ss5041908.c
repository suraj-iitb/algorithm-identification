#if 0
所用時間は約20分
ベルマンフォード法のアルゴリズムがテキスト中で詳しく解説されていたのでそれに従うのみで実装することができた。最初、infの設定を十分大きい数に設定できておらずWAを出したが、十分大きくすることで解決した。
#endif
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const ll mod=pow(10,9)+7;
const ll INF=pow(2,31)-1;
typedef pair<int,int> P;
typedef vector<int> vi;

struct Edge {
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

struct S {
    int v, cost;
    S(int v=0, int cost=0) : v(v), cost(cost) {}
    bool operator<(const S& s) const {
        return cost > s.cost;
    }
};

int V, E;
vector< vector<Edge> > G;
int main() {
  int r;
    cin >> V >> E >> r;
    G.clear(); G.resize(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(Edge(t, d));
    }

    vector<int> D(V, INF);
    D[r] = 0;
    priority_queue<S> que;
    que.push(S(r, 0));
    while (!que.empty()) {
        S c = que.top(); que.pop();
        for (int i = 0; i < G[c.v].size(); i++) {
            Edge& e = G[c.v][i];
            int ncost = D[c.v] + e.cost;
            if (D[e.to] > ncost) {
                D[e.to] = ncost;
                que.push(S(e.to, ncost));
            }
        }
    }
    for (int i = 0; i < V; i++) {
        if (D[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << D[i] << endl;
        }
    }

    return 0;
}
