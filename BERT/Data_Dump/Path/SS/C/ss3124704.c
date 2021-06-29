#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const ll inf = 100100100100100;


vector<ll> dijkstra(int s, vector< vector<pair<int,ll>>> l, int v){
    vector<ll> dist; rep(i,0,v) dist.push_back(inf); dist[s] = 0;
    priority_queue< pair<int, ll>,vector<pair<int, ll>>,greater<pair<int, ll>>> que; que.push(make_pair(0,s));

    while(!que.empty()){
        pair<int,ll> p = que.top(); que.pop();
        int vertex = p.second;
        if(dist[vertex] < p.first) continue;
        rep(i,0,l[vertex].size()){
            pair<int,ll> to = l[vertex][i];
            if(dist[to.second] > dist[vertex] + to.first){
                dist[to.second] = dist[vertex] + to.first;
                que.push(make_pair(dist[to.second],to.second));
            }
        }
    
    }
    return dist;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int v,e,s;
    cin >> v >> e >> s;
    vector<vector<pair<int,ll>>> alist;
    vector<pair<int,ll>> t;
    rep(i,0,v) alist.push_back(t);
    rep(i,0,e){
        int from, to, cost; cin >> from >> to >> cost;
        alist[from].push_back(make_pair(cost,to));
    }

   vector<ll> distances = dijkstra(s,alist,v);
   rep(i,0,v) if(distances[i] < inf) cout << distances[i] << endl; else cout << "INF" << endl;

}
