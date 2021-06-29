#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
#define INF 2147483647

struct edge {
    int s, t;
};
int V, E;

vector <edge> G[100010];

multimap <int, int> l;


ll d[500010];


void dijkstra(int s) {
    fill(d, d + V, INF);
    d[s] = 0;

    l.insert(make_pair(0, s));

    while (l.size() > 0) {
        int p = l.begin()->first;
        int v = l.begin()->second;
        l.erase(l.begin());

        if (d[v] < p) continue;

        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.s] > d[v] + e.t) {
                d[e.s] = d[v] + e.t;
                l.insert(make_pair(d[e.s], e.s));
            }
        }
    }
}


int main() {

    int r;
    cin >> V >> E >> r;
    for (int i = 0; i < E; i++) {
        edge e;
        int from;
        cin >> from >> e.s >> e.t;
        G[from].push_back(e);
    }

    dijkstra(r);

    for (int i = 0; i < V; i++) {
        if (d[i] != INF) cout << d[i] << endl;
        else cout << "INF" << endl;
    }
    return 0;
}
