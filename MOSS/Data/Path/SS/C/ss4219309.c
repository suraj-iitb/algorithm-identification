#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

struct edge { 
    int to;
    ll cost;
};

typedef vector<vector<edge>> Graph;

vector<ll> dijkstra(Graph G, ll s) {
    ll inf = 1e18;
    priority_queue<Pll, vector<Pll>, greater<Pll>> que;
    vector<ll> d(G.size(), inf);
    d[s] = 0;
    que.push(Pll(0, s));
    
    while (!que.empty()) {
        Pll p = que.top();
        que.pop();
        
        ll v = p.second;
        if (d[v] < p.first) continue;
        for (auto &i : G[v]) {
            edge e = i;
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(Pll(d[e.to], e.to));
            }
        }
    }
    return d;
}


int main() {
    int v, e, r;
    cin >> v >> e >> r;

    Graph G(v);
    for (int i = 0; i < e; i++) {
        ll s, t, d;
        cin >> s >> t >> d;
        edge e;  e.to = t;  e.cost = d;
        G[s].push_back(e);
    }

    vector<ll> d = dijkstra(G, r);
    ll inf = 1e18;
    for (int i = 0; i < v; i++) {
        if (d[i] == inf) cout << "INF" << endl;
        else cout << d[i] << endl;
    }

}

