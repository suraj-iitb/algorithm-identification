#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
typedef pair <ll, int> P;
const ll INF = 1LL << 60;

vector <ll> dijkstra(vector<vector<P>> &edge, int s) {
    vector <ll> dist(edge.size(), INF);
    priority_queue <P, vector<P>, greater<P>> q;
    q.push({0, s});
    dist[s] = 0;

    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int cur = p.second;
        ll cost = p.first;
        if (dist[cur] < cost) continue;
        for (P nxt : edge[cur]) {
            int next_node = nxt.second;
            ll cost_sum = cost + nxt.first;
            if (dist[next_node] > cost_sum) {
                dist[next_node] = cost_sum;
                q.push({cost_sum, next_node});
            }
        }
    }

    return dist;
}


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
void AOJ_GLR_1_A() {
    int V, E, r;
    cin >> V >> E >> r;

    vector<vector<P>> edge(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        ll d;
        cin >> s >> t >> d;
        edge[s].push_back({d, t});
    }

    vector <ll> dist = dijkstra(edge, r);
    for (ll d : dist) {
        if (d == INF) {
            cout << "INF\n";
        } else {
            cout << d << "\n";
        }
    }
}

int main() {
    AOJ_GLR_1_A();
    return 0;
}
