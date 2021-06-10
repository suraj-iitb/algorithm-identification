#include <bits/stdc++.h>
using namespace std;

using Edges = vector<vector<pair<int, int>>>;


vector<int> single_source_shortest_path(int r, const Edges & Es){
    vector<int> dist(Es.size(), -1);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, r));
    while (not pq.empty()){
        auto dv = pq.top();
        pq.pop();
        int d = -dv.first;
        int v = dv.second;
        if ((dist[v] != - 1) and (d >= dist[v])) continue;
        dist[v] = d;
        for (auto & uc : Es[v]){
            int u = uc.first;
            int c = uc.second;
            if ((dist[u] != -1) and (d + c >= dist[u])) continue;
            pq.push(make_pair(-(d + c), u));
        }
    }
    return dist;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E, r;
    cin >> V >> E >> r;
    Edges Es(V);
    while (E--){
        int s, t, d;
        cin >> s >> t >> d;
        Es[s].emplace_back(t, d);
    }
    auto dist = single_source_shortest_path(r, Es);
    for (auto d : dist){
        if (d == -1){
            cout << "INF" << '\n';
        }else{
            cout << d << '\n';
        }
    }
    return 0;
}
