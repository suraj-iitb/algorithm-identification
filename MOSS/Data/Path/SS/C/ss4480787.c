#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
struct edge
{
    int to, cost;
};
vector<vector<edge>> G(1e5 + 1);
int V, E;

vector<ll> dijkstra(int s) {
    vector<ll> dis(V, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    dis[s] = 0;
    while (!que.empty()) {
        P p = que.top(); que.pop();
        if (dis[p.second] < p.first) continue;
        for (auto e : G[p.second]) {
            if (dis[p.second] + e.cost < dis[e.to]) {
                dis[e.to] = dis[p.second] + e.cost;
                que.push(P(dis[e.to], e.to));
            }
        }
    }

    return dis;
}
int main()
{
    int s;
    cin >> V >> E >> s;
    rep(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({t, d});
    }

    vector<ll> dis = dijkstra(s);
    rep(i, V) {
        if (dis[i] == INF) cout << "INF" << endl;
        else cout << dis[i] << endl;
    }
    return 0;
}
