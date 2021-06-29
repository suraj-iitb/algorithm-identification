#include <bits/stdc++.h>
using namespace std;

typedef struct E{
    int to, cost;
}edge;
const int MAX_V = 200100;
const int INF = 1e9;
vector<vector<edge>> E(MAX_V);
int d[MAX_V];
void dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
    fill_n(d, MAX_V, INF);
    d[s] = 0;
    que.push(pair<int,int>(0, s));
    while(!que.empty()){
        pair<int,int> p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < E[v].size(); i++){
            edge t = E[v][i];
            if(d[t.to] > d[v] + t.cost){
                d[t.to] = d[v] + t.cost;
                que.push(pair<int,int>(d[t.to], t.to));
            }
        }
    }
}

int main(){
    int a, b, r;
    cin >> a >> b >> r;
    for(int i = 0; i < b; i++){    
        edge e;
        int s;
        cin >> s >> e.to >> e.cost;
        E[s].push_back(e);
    }
    dijkstra(r);
    for(int i = 0; i < a; i++){
        if(d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}
