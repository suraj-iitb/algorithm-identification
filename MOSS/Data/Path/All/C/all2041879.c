#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
using namespace std;

using weight = long long;

constexpr weight INF = 1e18;


// warshall-floyd
void warshall_floyd(std::vector<std::vector<weight>>& g) {
    int V = g.size();
    for(int k=0; k<V; ++k) {
        for(int i=0; i<V; ++i) {
            for(int j=0; j<V; ++j) {
                if(g[i][k] == INF || g[k][j] == INF) {
                    continue;
                }
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}


int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<weight>> g(v, vector<weight>(v, INF));
    for(int i=0; i<v; ++i) {
        g[i][i] = 0;
    }
    for(int i=0; i<e; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s][t] = d;
    }
    warshall_floyd(g);
    for(int i=0; i<v; ++i) {
        for(int j=0; j<v; ++j) {
            if(g[i][j] + g[j][i] < 0) {
                cout << "NEGATIVE CYCLE" << endl;
                return 0;
            }
        }
    }
    for(int i=0; i<v; ++i) {
        for(int j=0; j<v; ++j) {
            if(g[i][j] == INF) {
                cout << "INF";
            } else {
                cout << g[i][j];
            }
            if(j != v-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
