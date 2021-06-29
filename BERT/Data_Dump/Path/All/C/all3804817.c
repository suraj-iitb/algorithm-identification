#include <bits/stdc++.h>
using namespace std;

#define int long long

constexpr int INF = 1LL << 60;

pair<vector<vector<int>>, bool> warshallFloyd(const int V, vector<vector<int>> G) {
    for (int v = 0; v < V; v++) {
        G[v][v] = 0;
    }
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(G[i][k] >= INF || G[k][j] >= INF)
                    continue;
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    bool negativeLoop = false;
    for (int v = 0; v < V; v++) {
        if (G[v][v] < 0) {
            negativeLoop = true; 
            break;
        }
    }
    return {G, negativeLoop};
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V, vector<int>(V, INF));
    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        G[from][to] = cost;
    }
    vector<vector<int>> d; bool negLoop;
    tie(d, negLoop) = warshallFloyd(V, G);
    if (negLoop) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (d[i][j] >= INF) cout << "INF";
            else cout << d[i][j];
            if (j != V - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

