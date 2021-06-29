#include <bits/stdc++.h>
static const int MAX = 100001;
static const int INFTY = (1 << 30);
int V;
std::vector<std::pair<int, int> > G[MAX];

void dijkstra(int r) {
    std::priority_queue<std::pair<int, int> > pq;
    bool visited[MAX];
    int d[MAX];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        d[i] = INFTY;
    }
    d[r] = 0;
    pq.push({0, r}); //dist from target * -1, current node
    visited[r] = true;

    while ( !pq.empty() ) {
        std::pair<int, int> f = pq.top(); pq.pop();
        int current = f.second;
        visited[current] = true;

        if (d[current] < f.first * (-1)) continue;

        for (unsigned long i = 0; i < G[current].size(); i++) {
            int target = G[current][i].first;
            if (visited[target]) continue;
            if (d[target] > d[current] + G[current][i].second) {
                d[target] = d[current] + G[current][i].second;
                pq.push({d[target] * (-1), target});
            }
        }
    }

    for (int i = 0; i < V; i++) {
        (d[i] == INFTY) ? std::cout << "INF" << std::endl : std::cout << d[i] << std::endl;
    }
}



int main()
{
    int E, r, source, target, cost;
    std::scanf("%d %d %d", &V, &E, &r);
    for (int i = 0; i < E; i++) {
        std::scanf("%d %d %d", &source, &target, &cost);
        G[source].push_back({target, cost});

    }
    dijkstra(r);
    return 0;
}

