#include <bits/stdc++.h>
using namespace std;

bool has_nega_cycle(int V, const vector<vector<int>> &cost)
{
    for (int i = 0; i < V; ++i) {
        if (cost[i][i] < 0)
            return true;
    }
    return false;
}

string to_str(const int INF, int val)
{
    if (val == INF)
        return "INF";
    return to_string(val);
}

int main()
{
    static const int INF = 2e+9;
    int V, E;
    cin >> V >> E; 
    vector<vector<int>> cost(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i)
        cost[i][i] = 0;
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        cost[s][t] = d;
    }
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                int cost_ik = cost[i][k];
                int cost_kj = cost[k][j];
                if (cost_ik == INF || cost_kj == INF)
                    continue;
                cost[i][j] = min(cost[i][j], cost_ik + cost_kj);
            }
        }
    }
    if (has_nega_cycle(V, cost)) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int i = 0; i < V; ++i) {
        cout << to_str(INF, cost[i][0]);
        for (int j = 1; j < V; ++j)
            cout << " " << to_str(INF, cost[i][j]); 
        cout << endl;
    }
}


