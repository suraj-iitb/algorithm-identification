#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using PL = pair<ll,ll>;

vector<vector<PL>> hen;
const ll INF = 1e15;

vector<ll> dijkstra(int s, int n) {
    vector<ll> dist(n, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);
    dist[s] = 0;

    while(que.size()) {
        int vert = que.top().second;
        que.pop();
        for(auto i : hen[vert]) {
            if(dist[i.first] > dist[vert] + i.second) {
                dist[i.first] = dist[vert] + i.second;
                que.emplace(dist[i.first], i.first);
            }
        }
    }

    return dist;
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    hen.resize(n);

    for(int i = 0; i < m; i++) {
        int a, b, d; cin >> a >> b >> d;
        hen[a].emplace_back(b, d);
        //hen[b].emplace_back(a, d);
    }

    auto dist = dijkstra(s, n);
    for(int i  = 0; i < n; i++) {
        cout << (dist[i] >= INF ? "INF" : to_string(dist[i])) << endl;
    }


}
