#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

struct edge {
    int to;
    int cost;
};

int V, E, r;


vector<vector<edge>> G;

vector<int> dist;

int main()
{
    cin >> V >> E >> r;

    G.resize(V);
    dist.assign(V, 0);

    for (int i = 0; i < V; i++) {
        dist[i] = (i == r ? 0 : INF);
    }

    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;

        G[s].push_back(edge{t, d});
        //        G[t].push_back(edge{s, d});
    }

    priority_queue<int> pq;
    pq.push(r);

    while (!pq.empty()) {
        int t = pq.top();
        pq.pop();

        for (auto i : G[t]) {
            int to = i.to;
            int cost = i.cost;

            if (dist[to] > dist[t] + cost) {
                dist[to] = dist[t] + cost;
                pq.push(to);
            }
        }
    }

    for (int i = 0; i < V; i++){
        if(dist[i] == INF){
            cout << "INF" << endl;
        }else{
            cout << dist[i] << endl;
        }
    }
}
