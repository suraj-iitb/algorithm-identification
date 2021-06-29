#include <bits/stdc++.h>

using namespace std;
#define INF 1e12
static const int WHT = 0;
static const int GRY = 1;
static const int BLK = 2;

void dijkstra(  const vector<vector<pair<int,int> > > &adj,
                vector<long> &d,
                vector<int> &color,
                int s)
{
    priority_queue<pair<int,int>,
       std::vector<pair<int,int> >,
       greater<pair<int,int> > > PQ; 
    d[s] = 0;
    PQ.push(make_pair(d[s],s));
    color[s] = GRY;

    while(!PQ.empty()){
        pair<int,int> f = PQ.top();
        int u = f.second;
        PQ.pop();
        color[u] = BLK;

        if(d[u] < f.first) continue;
        for(auto itr = adj[u].begin(); itr != adj[u].end();itr++){
            int v = itr->first;
            if(color[v] != BLK){
                if(d[v] > d[u] + (long)itr->second){
                    d[v] = d[u] + (long)itr->second;
                    color[v] = GRY;
                    PQ.push(make_pair(d[v],v));
                }
            }
        }
    }

    
}

int main()
{
    // ----- Input ----- //
    int V,E,r;
    int s,t,w;

    cin >> V >> E >> r;
    vector<vector<pair<int,int> > > adj(V);
    vector<long> d(V,INF);
    vector<int> color(V,0);
    for(int i = 0;i < E;i++){
        cin >> s >> t >> w;
        adj[s].push_back(make_pair(t,w));
    }
    dijkstra(adj,d,color,r);

    for(int i =0;i < V;i++){
        if(d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}


