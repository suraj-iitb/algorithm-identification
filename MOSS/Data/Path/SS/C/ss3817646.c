// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long
#define vi vector<int>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

#define MAX_V 100005
#define INF 1e9

int V, E, r, s, t, cost, d[MAX_V];

struct edge {ll to, cost;};
typedef pair<int, int> P; //(最短距離, 頂点番号)

vector<edge> G[MAX_V];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

void solve(){
    dijkstra(r);

    rep(i,V){
        if(d[i] == INF)
            cout << "INF" << endl;
        else
            cout << d[i] << endl;
    }
}

int main(){
    cin >> V >> E >> r;

    rep(i,E){
        cin >> s >> t >> cost;
        edge buff;
        buff.to = t, buff.cost = cost;
        G[s].push_back(buff);
    }

    solve();
}

