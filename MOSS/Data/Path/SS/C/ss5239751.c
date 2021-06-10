#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const ll INF = 1000000000000000000LL;

void Main() {
    ll V, E, start;
    cin >> V >> E >> start;
    typedef pair<ll, ll> to_weight;
    vector<set<to_weight>> graph(V, set<to_weight>());
    while (E--) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].insert(make_pair(t, d));
    }

    typedef pair<ll, ll> dist_curr;
    priority_queue<dist_curr, vector<dist_curr>, greater<dist_curr>> q;
    vector<ll> d(V, INF);
    q.push(make_pair(0, start));
    d[start] = 0;
    while (!q.empty()) {
        ll dist = q.top().first;
        ll curr = q.top().second;
        q.pop();
        if (d[curr] < dist) {
            continue;
        }
        for (auto edge : graph[curr]) {
            ll to = edge.first;
            ll weight = edge.second;
            if (d[to] > d[curr] + weight) {
                d[to] = d[curr] + weight;
                q.push(make_pair(d[to], to));
            }
        }
    }
    for (ll i = 0; i < V; ++i) {
        if (d[i] == INF) {
            cout << "INF" << endl;
        }
        else {
            cout << d[i] << endl;
        }
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

