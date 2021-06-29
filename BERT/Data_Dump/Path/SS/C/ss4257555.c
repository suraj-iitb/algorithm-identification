#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;

typedef pair<int, int> P;  // firstは最短距離、secondは頂点の番号
const int MAX_V = 100010;
struct edge {
    int to,cost;
};
int V;
vector<edge> G[MAX_V];  //重み付き有効グラフの隣接リスト表現
int d[MAX_V];

void dijkstra(int s){
    //greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>,greater<P> > que;
    fill(d,d+V,inf);
    d[s] = 0;
    que.push(P(0,s));

     while(!que.empty()){
         P p = que.top(); que.pop();     // firstは最短距離、secondは頂点の番号
         int v = p.second;
         if(d[v] < p.first) continue;  
         for(int i = 0; i < G[v].size(); i++){
             edge e = G[v][i];
             if(d[e.to] > d[v] + e.cost){
                 d[e.to] = d[v] + e.cost;
                 que.push(P(d[e.to],e.to));
             }
         }
    }
}


int main()
{
    int e,r;
    cin >> V >> e >> r;
    for(int i = 0; i < e; i++){
        int s,t,u;
        cin >> s >> t >> u;
        struct edge e;
        e.to = t; e.cost = u;
        G[s].push_back(e);
    }
    dijkstra(r);
    for(int i = 0; i < V; i++){
        if(d[i] == inf){
            cout << "INF" << endl;
        }else{
            cout << d[i] << endl;
        }
    }
}

