#include <bits/stdc++.h>
using namespace std;
const long long inf = 10000000000000ll;
typedef pair<long long, int> pa;

int V, E, R;
long long dist[100000];
struct edge{ int s, t, d; };
vector<edge> graph[100000];

int main(){

    cin >> V >> E >> R;
    for(int i = 0; i < E; i++){
        edge e;
        cin >> e.s >> e.t >> e.d;
        graph[e.s].push_back(e);
    }

    fill(dist, dist + V, inf);
    dist[R] = 0;
    
    priority_queue<pa, vector<pa>, greater<pa>> que;
    que.push({0, R});

    while(!que.empty()){
        pa p = que.top();
        que.pop();
        int v = p.second, d = p.first;
        if(dist[v] < d)continue;
        for(edge e : graph[v]){
            if(dist[e.t] > d + e.d){
                dist[e.t] = d + e.d;
                que.push({d + e.d, e.t});
            }
        }
    }

    for(int i = 0; i < V; i++){
        if(dist[i] == inf)cout << "INF\n";
        else cout << dist[i] << '\n';
    }

}
