#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
#define all(x) (x).begin(),(x).end()

#define INF 1e+9
#define MAX_V 100000

struct edge {
    int to;
    int cost;
};

// <最短距離, 頂点の番号>
using P = pair<int, int>;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int e, r;
    cin >> V >> e >> r;

    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;

        edge e = {b, c};
        G[a].push_back(e);
    }
    dijkstra(r);
    for(int i=0; i <V; i++){
      if(d[i] == INF){
        cout << "INF" << ln;
      } else{
      cout << d[i] << ln;
      }
    }
  
}

