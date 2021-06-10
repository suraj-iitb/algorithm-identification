#include <bits/stdc++.h>
//#include <atcoder/all>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using namespace atcoder;
// using ll = long long;
// using P = pair<int,int>;

struct edge {int to, cost; };
int V, E;
vector<vector<edge> > G;
vector<long long> d;

void dijkstra(int s){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    d.resize(V, LONG_LONG_MAX);
    d[s] = 0;
    que.push({0, s});
    while(!que.empty()){
        pair<int, int> p = que.top(); que.pop();
        long long v = p.second;
        if (d[v] < p.first) continue;
        rep(i, G[v].size()){
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push({d[e.to], e.to});
            }
        }
    }
}



int main(){
    int s;
    cin >> V >> E >> s;
    G.resize(V, vector<edge>());
    rep(i,E){
        int a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    dijkstra(s);
    rep(i,V){
        if(d[i] == LONG_LONG_MAX){
            cout << "INF" << endl;
        }else{
            cout << d[i] << endl;
        }
    }
    return 0;
}

