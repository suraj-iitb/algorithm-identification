#include<bits/stdc++.h>
using namespace std;

int V, E, R, s, t, d;
const int Inf = 10000*100000+100;

int main(){
    cin >> V >> E >> R;
    vector<int> dist(V, Inf);
    vector<vector<int>> edges(V), cost(V);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    pair<int,int> u, v;
    for(int i = 0; i < E; ++i){
        cin >> s >> t >> d;
        edges[s].push_back(t);
        cost[s].push_back(d);
    }
    dist[R] = 0;
    Q.push(make_pair(0,R));
    while(!Q.empty()){
        u = Q.top();
        Q.pop();
        for(int i = 0; i < edges[u.second].size(); ++i){
            if(dist[edges[u.second][i]] > dist[u.second] + cost[u.second][i]){
                dist[edges[u.second][i]] = dist[u.second] + cost[u.second][i];
                Q.push(make_pair(dist[edges[u.second][i]], edges[u.second][i]));
            }
        }
    }
    for(auto d: dist) d == Inf ? cout << "INF" << endl : cout << d << endl;
    return 0;
}
