#include <bits/stdc++.h>

/**
 * startからすべての頂点への最小距離を求める O(|E| log |V|)
 * 負辺はないものとする
 */
std::vector<int> dijkstra(int start, std::vector<std::vector<std::pair<int, int>>> graph) {
    const unsigned long num_node = graph.size();

    //[(最短距離, node番号)]のque(距離が近い順にとりだす)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
    que.push({0, start});

    std::vector<int> prev(num_node, -1);            // 経路復元用
    std::vector<int> distance(num_node, INT_MAX);   // startからの距離
    distance[start] = 0;

    while (not que.empty()) {
        int now_dist, from;
        std::tie(now_dist, from) = que.top();
        que.pop();

        if (distance.at(from) < now_dist) {
            continue;
        }
        for (const std::pair<int, int> &p : graph.at(from)) {
            int to = p.first;
            int dist = p.second;
            int new_dist = now_dist + dist;

            if (new_dist < distance.at(to)) {
                prev.at(to) = from;
                distance.at(to) = new_dist;
                que.push({new_dist, to});
            }
        }
    }

    return distance;
}

using namespace std;

int main(void) {
    int V, E, r;
    cin >> V >> E >> r;

    vector<vector<pair<int, int>>> graph(V);
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].emplace_back(make_pair(t, d));
    }

    auto distance = dijkstra(r, graph);
    for (int i = 0; i < distance.size(); ++i) {
        if (distance[i] == INT_MAX) {
            cout << "INF" << endl;
        }
        else {
            cout << distance[i] << endl;
        }
    }

    return 0;
}
