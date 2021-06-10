#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<numeric>
#include<iomanip>
#include<climits>
#include<queue>

using namespace std;
using ll = long long;

int main() {
    int v, e, r;
    cin >> v >> e >> r;
    vector<vector<pair<int, int>>> graph(v, vector<pair<int, int>>());
    vector<int> cost(v, INT_MAX);
    for (int i=0; i<e; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back(make_pair(t, d));
    }
    priority_queue<int> q;
    q.push(r);
    cost[r] = 0;
    while (!q.empty()) {
        int curr = q.top();
        q.pop();
        for (auto&e : graph[curr]) {
            if (cost[curr] + e.second < cost[e.first]) {
                cost[e.first] = cost[curr] + e.second;
                q.push(e.first);
            }
        }
    }
    for (auto& e: cost) {
        if (e == INT_MAX)
            cout << "INF" << endl;
        else
            cout << e << endl;
    }
}

