#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i < (n); i++)
template<class T> istream& operator >> (istream& s, vector<T>& v)
{ for (T& x: v) { s >> x; } return s;}

using ll = long long;
using pii = pair<int, int>;

#define INF (LLONG_MAX>>2)
int main()
{
    int V, E, R; cin >> V >> E >> R;
    vector<vector<pii>> g(V);
    for (int i = 0; i < E; i++) {
        int s, t, d; cin >> s >> t >> d;
        g[s].emplace_back(d, t);
    }

    vector<ll> dist(V, INF);
    vector<bool> done(V, false);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[R] = 0;
    q.emplace(0, R);
    while (!q.empty()) {
        auto s = q.top(); q.pop();
        const auto& v = s.second, d = s.first;
        if (d > dist[v]) continue;
        dist[v] = d;
        //done[v] = true;
        for (const auto& e : g[v]) {
            const auto& ev = e.second, ed = e.first;
            //if (done[ev]) continue;
            if (dist[v] + ed < dist[ev]) {
                dist[ev] = dist[v] + ed;
                q.emplace(dist[ev], ev);
            }
        }
    }

    for (const auto& d : dist) {
        if (d == INF) cout << "INF" << endl;
        else cout << d << endl;
    }
}

