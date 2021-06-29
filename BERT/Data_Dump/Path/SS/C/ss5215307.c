#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int>;
using Graph = vector<vector<Pair>>;
using PQueue = priority_queue<Pair, vector<Pair>, greater<Pair>>;

int main()
{
    constexpr int64_t INF = 1e+10;
    int V, E, r;
    cin >> V >> E >> r;
    Graph graph(V);
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        graph.at(s).push_back({d, t});
    }
    vector<int64_t> dist(V, INF);
    PQueue pq;
    dist.at(r) = 0;
    pq.push({0, r});
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        auto s = top.second;
        auto dist_s = top.first;
        if (dist.at(s) < dist_s)
            continue;
        for (auto pr : graph.at(s)) {
            auto t = pr.second;
            auto dist_t = dist_s + pr.first;
            if (dist.at(t) <= dist_t)
                continue;
            dist.at(t) = dist_t;
            pq.push({dist_t, t});
        }
    }
    for (int i = 0; i < V; ++i) {
        auto dist_i = dist.at(i);
        if (dist_i == INF)
            cout << "INF" << endl;
        else
            cout << dist_i << endl;
    }
}

