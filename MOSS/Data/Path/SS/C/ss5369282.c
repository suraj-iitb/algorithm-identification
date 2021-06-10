#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
#define inf 5000000000
struct e{
    int t;
    int d;
};
int V,E;
vector <e> G[100010];
multimap <int,int> l;
ll d[500010];
void dijkstra(int s){
    fill(d,d+V,inf);
    d[s] = 0;
    l.insert(make_pair(0,s));
    while(l.size() > 0){
        int p = l.begin()->first;
        int v = l.begin()->second;
        l.erase(l.begin());
        if(d[v] < p) continue;
        for(int i = 0;i < G[v].size(); i++){
            e e = G[v][i];
            if(d[e.t] > d[v] + e.d){
                d[e.t] = d[v] + e.d;
                l.insert(make_pair(d[e.t], e.t));
            }
        }
    }
}
int main(){
    int r;
    cin >> V >> E >> r;
    for(int i = 0;i < E; i++){
         e e;
        int from;
        cin >> from >> e.t >> e.d;
        G[from].push_back(e);
    }
    dijkstra(r);
    for(int i = 0;i < V; i++){
        if(d[i] != inf) cout << d[i] << endl;
        else cout << "INF" <<endl;
    }
    return 0;
}
