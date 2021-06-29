#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const long long INF = (1LL << 32);

class FloydWarshall {
    private:
    int size;
    vector<vector<long long>> d;

    public:
    FloydWarshall(int n) {
        size = n;
        d.resize(n);
        for (int i = 0; i < n; ++i) {
            d[i].resize(n);
            for (int j = 0; j < n; ++j) {
                d[i][j] = i == j ? 0 : INF;
            }
        }
    }

    void add_edge(int u, int v, int w) { d[u][v] = w; }

    long long get_distance(int src, int dest) { return d[src][dest]; }

    void set_distances() {
        for (int k = 0; k < size; ++k)
            for (int i = 0; i < size; ++i)
                for (int j = 0; j < size; ++j)
                    if (d[i][k] < INF && d[k][j] < INF)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    bool has_negative_cycle() {
        for (int i = 0; i < size; ++i) {
            if (d[i][i]) return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    FloydWarshall fw(V);

    for (int i = 0; i < E; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        fw.add_edge(s, t, w);
    }

    fw.set_distances();

    if (fw.has_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                ll d = fw.get_distance(i, j);
                if (d < INF)
                    cout << d;
                else
                    cout << "INF";
                if (j < V - 1) cout << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
