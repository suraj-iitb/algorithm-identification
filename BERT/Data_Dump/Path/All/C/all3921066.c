#include <bits/stdc++.h>
using namespace std;

template<class T>
void WarshallFloyd(vector<vector<T>> &G, T INF) {
    for(int i = 0; i < G.size(); ++i) G[i][i] = 0;
    for(int k = 0; k < G.size(); ++k) {
        for(int i = 0; i < G.size(); ++i) {
            for(int j = 0; j < G.size(); ++j) {
                if(G[i][k] == INF || G[k][j] == INF) continue;
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

void solve() {
    int V, E;
    cin >> V >> E;
    const long long INF = 1e18;
    vector<vector<long long>> G(V, vector<long long>(V, INF));
    for(int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = c;
    }
    WarshallFloyd(G, INF);
    for(int i = 0; i < V; ++i) if(G[i][i] < 0) {
        cout << "NEGATIVE CYCLE" << '\n';
        return;
    }
    for(auto &v : G) {
        for(int i = 0; i < (int)v.size(); ++i) {
            if(i) cout << " ";
            if(v[i] == INF) cout << "INF";
            else cout << v[i];
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

