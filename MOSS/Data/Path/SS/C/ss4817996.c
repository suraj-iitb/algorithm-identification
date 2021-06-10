#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)(1e9 + 5)
#define MOD (int)(1e9 + 7) 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v, e, src;
    cin >> v >> e >> src;
    vector<vector<pair<int, int>>> edges(v, vector<pair<int, int>>());
    for(int i = 0; i < e; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({y, z});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, src});
    vector<bool> vis(v, false);
    vector<int> cost(v, INF);
    cost[src] = 0;
    int done = 0;
    while(!q.empty()) {
        pair<int, int> now = q.top(); q.pop();
        if(!vis[now.second]) {
            vis[now.second] = true;
            cost[now.second] = now.first;
        }
        else {
            continue;
        }
        for(auto i : edges[now.second]) {
            if(!vis[i.first]) {
                q.push({i.second + now.first, i.first});
            }
        }
    }
    for(int i : cost) {
        if(i == INF) cout << "INF\n";
        else cout << i << '\n';
    }
    return 0;
}
