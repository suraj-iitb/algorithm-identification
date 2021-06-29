#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0; i<n; i++)
const int INF= 1LL << 30;

vector<int> dijkstra(const vector<vector<pair<int,int>>>& edge, int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> que;
    que.push(make_pair(0,start)); //距離、点
    int visited[edge.size()]= {0}; //確定点
    vector<int> costs(edge.size(),INF); //確定点
    int from,dist, to,cost;

    while(!que.empty()){
        tie(dist,from) = que.top(); que.pop();
        if(visited[from] == 1) continue;
        visited[from] = 1;  costs[from] = dist;

        for(auto e:edge[from]){
            tie(to,cost) = e;
            if(visited[to] == 1)continue;
            que.push(make_pair(dist+cost, to));
        }

    }
    return costs;
}
int main(){
    int v,e,r;//v:点,e:辺,r:始点
    cin >> v >> e >> r;
    vector<vector<pair<int,int>>>edge(v);
    REP(i,e){
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b,c));
    }
    auto costs= dijkstra(edge, r);
    for(int x:costs){
        if(x>=INF) cout << "INF" << endl;
        else cout << x << endl;
    }

}
