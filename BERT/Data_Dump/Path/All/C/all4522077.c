#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

bool warshall_floyd(const int n,
                    vector<vector<pair<int, int>>>& g,
                    vector<vector<int64_t>>& cost) {
    for (auto i = 0; i < n; i++) {
        // 自身への距離は0
        cost[i][i] = 0;
        for (auto& elm : g[i]) {
            // 頂点iからの距離で初期化
            cost[i][elm.first] = elm.second;
        }
    }

    for (auto k = 0; k < n; k++) {
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                if(cost[i][k] == INT64_MAX or cost[k][j] == INT64_MAX) continue;
                // 直接行く場合とkを経由する場合でより小さい距離を採用する
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    bool isNegativeCycle = false;
    for (auto i = 0; i < n; i++) {
        // 自身へのコストが0以下なら負の閉路がある
        if (cost[i][i] < 0) isNegativeCycle = true;
    }

    return isNegativeCycle;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>(0));
    for (auto i = 0; i < m; i++) {
        int s, t, d; cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }

    vector<vector<int64_t>> cost(n, vector<int64_t>(n, INT64_MAX));
    bool isNegativeCycle = warshall_floyd(n, g, cost);

    if(isNegativeCycle) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < n - 1; j++) {
            if(cost[i][j] == INT64_MAX) cout << "INF ";
            else cout << cost[i][j] << " ";
        }
        if(cost[i][n - 1] == INT64_MAX) cout << "INF";
        else cout << cost[i][n - 1];
        cout << endl;
    }

    return 0;
}
