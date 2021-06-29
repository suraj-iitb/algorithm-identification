#include <bits/stdc++.h>
using namespace std;

#define MAX_V 100001
#define INF (1e9 + 1)

struct edge {
    int des,cost;
};

int V,E,R,a,b,c;
vector< edge > G[MAX_V];
int dist[MAX_V];

void Dijkstra(){
    for (int i = 0; i < MAX_V; i++)dist[i] = INF;
    dist[R] = 0;
    priority_queue< pair<int,int> > Q;
    Q.push( make_pair(0,R) );
    while (Q.size()){
        pair<int,int> p=Q.top();
        Q.pop(); 
        int cost = -p.first, pos = p.second;
        if (cost > dist[pos]) continue; 
        for (int i = 0; i < G[pos].size(); i++){
            edge e = G[pos][i];
            int des = e.des;
            int newcost = cost + e.cost;
            if (newcost < dist[des]){
                dist[des] = newcost;
                Q.push(make_pair(-dist[des],des));
            }
        }
    }
    for (int i = 0; i < V; i++){
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

int main(){
    cin >> V >> E >> R;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        G[a].push_back((edge){b,c});
    }
    Dijkstra();
    return 0;
    
}
