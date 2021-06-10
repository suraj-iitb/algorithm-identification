#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<long long>> dist(V, vector<long long>(V, INF));
    for (int i = 0; i < E; i++)
    {
        long long s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    for (int i = 0; i < V; i++)
    {
        dist[i][i] = 0;
    }

    bool mc = false;
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if(dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if(dist[i][i] < 0) mc = true;
    }

    if(mc) cout << "NEGATIVE CYCLE" << endl;
    else{
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if(dist[i][j] == INF) cout << "INF";
                else cout << dist[i][j];
                if(j == V - 1) cout << endl;
                else cout << " ";
            }
        }
    }
}
