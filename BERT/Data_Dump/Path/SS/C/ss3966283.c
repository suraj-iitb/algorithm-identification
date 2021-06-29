#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

struct edge{int to; ll cost;};
typedef pair<ll,int> P;

int V;
vector<edge> G[100005];
ll d[100005];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d,d+V,INF);
    d[s] =0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        FOR(i,0,G[v].size()){
            edge e = G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    return ;
}

int main(){
    int E; cin >> V >> E;
    int st; cin >> st;
    int x,y; ll co;
    edge ed;
    FOR(i,0,E){
        cin >> x >> y >> co;
        ed.to=y;
        ed.cost=co;
        G[x].push_back(ed);
    }
    dijkstra(st);
    FOR(i,0,V){
        if(d[i]==INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}
