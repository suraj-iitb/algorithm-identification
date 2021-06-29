#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int v, e, r;
const long long INF = 1e18;
const int V_MAX = 100010;
struct edge{
    int to;
    long long cost;
};
vector<edge> G[V_MAX];
long long D[V_MAX];

void dijkstra(int start){
    priority_queue<P, vector<P>, greater<P>> q;
    for(int i = 0; i < v; i++){
        D[i] = INF;
    }
    D[start] = 0;
    q.push({start, 0});

    while(!q.empty()){
        P p = q.top();
        q.pop();
        int now = p.first;
        if(D[now] < p.second) continue;
        for(int i = 0; i < G[now].size(); i++){
            edge e = G[now][i];
            if(D[e.to] > D[now] + e.cost){
                D[e.to] = D[now] + e.cost;
                q.push({e.to, D[e.to]});
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> v >> e >> r;
    for(int i = 0; i < e; i++){
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({t, d});
    }

    dijkstra(r);

    for(int i = 0; i < v; i++){
        if(D[i] == INF) cout << "INF" << endl;
        else cout << D[i] << endl;
    }


    return 0;
}
