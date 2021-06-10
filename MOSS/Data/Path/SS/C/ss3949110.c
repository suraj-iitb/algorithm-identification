#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

struct edge {
    int to;
    ll cost;
};

struct status {
    ll cost;
    int v;

    bool operator<(const status &another) const { return cost < another.cost; };

    bool operator>(const status &another) const { return cost > another.cost; };
};


int n;
vector<vector<edge>> graph;
vector<ll> dis;

const ll INF = 1145141919810364364;

void dijkstra(int s) {
    priority_queue<status, vector<status>, greater<>> que;
    dis = vector<ll>(n, INF);
    dis[s] = 0;
    que.push({0, s});

    while (!que.empty()) {
        status now = que.top();
        que.pop();

        if (dis[now.v] < now.cost)continue;

        for (auto &next:graph[now.v]) {
            if (dis[next.to] > dis[now.v] + next.cost) {
                dis[next.to] = dis[now.v] + next.cost;
                que.push({dis[next.to], next.to});
            }
        }
    }
}

int main() {
    int m, start;
    cin >> n >> m >> start;
    graph = vector<vector<edge>>(n);
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    dijkstra(start);

    for (int i = 0; i < n; i++)cout << (dis[i] == INF ? "INF" : to_string(dis[i])) << endl;
    return 0;
}
