#include <limits>
#include <vector>
using namespace std;

template <typename T>
void floyd_warshall(vector<vector<T>> &dist) {
    const T INF = numeric_limits<T>::max();
    size_t V = dist.size();
    for(size_t k = 0; k < V; ++k) {
        for(size_t i = 0; i < V; ++i) {
            for(size_t j = 0; j < V; ++j) {
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

#include <iostream>
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> dist(V, vector<int>(V, numeric_limits<int>::max()));
    for(int i=0; i<V; ++i) dist[i][i] = 0;

    for(int i=0; i<E; ++i) {
        int s,t,d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    floyd_warshall<int>(dist);
    for(int i=0; i<V; ++i) {
        if(dist[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    for(int i=0; i<V; ++i) {
        for(int j=0; j<V; ++j) {
            if(dist[i][j] == numeric_limits<int>::max()) cout << "INF";
            else cout << dist[i][j];
            cout << (j+1==V ? '\n' : ' ');
        }
    }
}
