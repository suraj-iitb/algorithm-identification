#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 1000000007;

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)
vector<long long> dijkstra(vector<vector<pair<long long, long long>>> graph, long long s) {
    vector<long long> ans(graph.size(), -1);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>
        pq;
    pq.push({0, s});
    while (pq.size() > 0) {
        int cur1 = 0;
        int cur2 = 0;
        if (ans[pq.top().second] != -1) {
            pq.pop();
        } else {
            cur1 = pq.top().first;
            cur2 = pq.top().second;
            pq.pop();
            ans[cur2] = cur1;
            for (long long i = 0; i < graph[cur2].size(); i++) {
                pq.push({cur1 + graph[cur2][i].second, graph[cur2][i].first});
            }
        }
    }
    return ans;
}
vector<vector<pair<long long, long long>>> graph;
signed main() {
    int v, e, r;
    cin >> v >> e >> r;
    vector<long long> as(v);
    graph.resize(v);
    REP(i, e) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    as = dijkstra(graph, r);
    REP(i, v) {
        if (as[i] == -1) {
            cout << "INF" << endl;
            continue;
        }
        cout << as[i] << endl;
    }
}
