#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct FloydWarshall {
    int n;
    vector<vector<ll>> g;
    vector<vector<ll>> dists;
    
    FloydWarshall(int n):n(n) {
        g.assign(n + 1, vector<ll>(n + 1, INF));
    }
    
    void addEdge(int from, int to, ll w) {
        g[from][to] = w;
    }
    
    bool solve() {
        dists.assign(n + 1, vector<ll>(n + 1, INF));
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                dists[i][j] = g[i][j];
            }
            dists[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dists[i][k] < INF && dists[k][j] < INF && 
                            dists[i][k] + dists[k][j] < dists[i][j]) {
                        dists[i][j] = dists[i][k] + dists[k][j];
                        if (i == j && dists[i][j] < 0) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    } 
};

int main() {
    int v, e, s;
    cin >> v >> e;
    FloydWarshall d(v);
    for (int i = 0; i < e; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        d.addEdge(from, to, w);
    }
    if (!d.solve()) {
        cout << "NEGATIVE CYCLE" << endl;
    }
    
    else {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (j > 0) {
                    cout << " ";
                }
                if (d.dists[i][j] == INF) {
                    cout << "INF";
                }
                else {
                    cout << d.dists[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
