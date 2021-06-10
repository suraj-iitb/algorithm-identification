#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge { ll to, cost; };
ll inf = 1e18;

ll V, E, r;
vector<P> G[100010];
ll d[100010];

void dijkstra(ll s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, inf);
    d[s] = 0;
    que.push(P(0, s));
    
    while (!que.empty()) {
        P p = que.top();  que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            P e = G[v][i];
            if (d[e.first] > d[v] + e.second) {
                d[e.first] = d[v] + e.second;
                que.push(P(d[e.first], e.first));
            }
        }
    }
}

int main(void){
    cin >> V >> E >> r;
    for (int i = 0; i < E; i++) {
        ll s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(P(t, d));
        //G[t].emplace_back(s, d);
    }
    
    dijkstra(r);
    for (int i = 0; i < V; i++) {
        if (d[i] == 1e18) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    
    
    
}

