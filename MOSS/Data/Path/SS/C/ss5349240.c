#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000
using namespace std;

struct Edge{
    int to;
    int cost;
};

bool operator> (const Edge &Edge1, const Edge &Edge2){
    return Edge1.cost > Edge2.cost;
};


void Dijkstra(vector<vector<Edge> > G, int r, int V) {
    vector<int> distance;
    priority_queue<Edge, vector<Edge>, greater<Edge> > Q;

    Q.push({r, 0});
    distance.resize(V, INF);
    distance[r] = 0;

    while (!Q.empty()) {
        auto now = Q.top();
        Q.pop();

        int nnode = now.to;
        int ndist = now.cost;

        if (ndist > distance[nnode])continue;

        for (int i = 0; i < G[nnode].size(); i++) {
            Edge next;
            next = G[nnode].at(i);
            int nextDirection = next.to;
            int nextCost = next.cost;

            if (distance[nextDirection] <= distance[nnode] + nextCost)continue;
            distance[nextDirection] = distance[nnode] + nextCost;
            Q.push({nextDirection, distance[nextDirection]});
        }
    }

    for (int i = 0; i < V; i++) {
        if (distance[i] == INF) {
            cout << "INF" << endl;
            continue;
        }
        cout << distance[i] << endl;
    }
}

int main() {
    int V, E, r;
    cin >> V >> E >> r;

    vector<vector<Edge> > G;
    G.resize(V);

    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({t, d});
    }

    Dijkstra(G, r, V);

    return 0;
}

