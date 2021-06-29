#include<bits/stdc++.h>
using namespace std;

const int INF=1000000000;

struct edge{int to,cost;};
typedef pair<int,int>P;

int V,E,r;
vector<edge>G[100010];
int d[100010];

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P>>que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first)continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}


int main(){
    cin>>V>>E>>r;
    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;
        struct edge e;
        e.to=b; e.cost=c;
        G[a].push_back(e);
    }
    dijkstra(r);
    for(int i=0;i<V;i++){
        if(d[i]==INF)cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
    return 0;
}
