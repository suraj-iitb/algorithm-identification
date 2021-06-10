#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

typedef pair<long long,long long> P;

int v,e,r;

struct edge{
    int to;
    long long cost;
    edge(int _to,long long _cost):to(_to),cost(_cost){}
};

vector<edge> G[1000010];
long long d[1000010];

void dijkstra(int start){
    priority_queue<P,vector<P>,greater<P>> que;
    
    for(int i=0;i<v;i++){
        d[i]=1e12;
    }
    d[start]=0;
    que.push(P(d[r],r));
    
    while(!que.empty()){
        P p=que.top();
        que.pop();
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

int main(void){
    cin>>v>>e>>r;
    for(int i=0;i<e;i++){
        int s,t,d;
        cin>>s>>t>>d;
        G[s].push_back(edge(t,d));
    }
    
    dijkstra(r);
    
    for(int i=0;i<v;i++){
        if(d[i]!=1e12)cout<<d[i]<<endl;
        else cout<<"INF"<<endl;
    }
    return 0;
}
