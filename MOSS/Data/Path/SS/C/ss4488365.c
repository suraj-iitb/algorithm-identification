#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

int main(){
    int v, e, r;
    cin >> v >> e >> r;

    vector<vector<pair<int, int>>> g(v, vector<pair<int, int>>(0));
    for (auto i = 0; i < e; i++) {
        int s, t, d; cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }

    vector<int> cost(v, -1);
    // デフォルトは降順 first = dist, second = point
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, r}); cost[r] = 0;
    while(not q.empty()){
        pair<int, int> start = q.top();
        q.pop();
//        cout << start.second << " " << start.first << " " << cost[start.second] << endl;
        if(cost[start.second] < start.first) continue;
        for (auto elm : g[start.second]) {
            int dist = start.first + elm.second;
            if(cost[elm.first] > dist or cost[elm.first] < 0) {
                cost[elm.first] = dist;
                q.push({dist, elm.first});
            }
        }
    }

    for (auto i = 0; i < v; i++) {
        if(cost[i] < 0) cout << "INF" << endl;
        else cout << cost[i] << endl;
    }

    return 0;
}
