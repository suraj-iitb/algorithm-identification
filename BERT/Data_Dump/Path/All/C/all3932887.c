#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const long long linf = 1e18;

using Matrix = vector<vector<long long>>;

void warshall_floyd(Matrix& m)
{
    const int V = m.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
            }
        }
    }
}

int main()
{
    int v, e; cin >> v >> e;
    Matrix m(v, vector<ll>(v, linf));
    for (int i = 0; i < v; i++) m[i][i] = 0;
    for (int i = 0; i < e; i++) {
        int s, t, d; cin >> s >> t >> d;
        m[s][t] = d;
    }
    warshall_floyd(m);
    for (int i = 0; i < v; i++) {
        if (m[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << (m[i][j] >= linf/2 ? "INF" : to_string(m[i][j])) << " \n"[j==v-1];
        }
    }
    return 0;
}
