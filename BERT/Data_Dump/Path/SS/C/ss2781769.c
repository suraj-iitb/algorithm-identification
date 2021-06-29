#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

int INF=10000*100000+100;
const int MAX_V=100005;

using namespace std;

struct edge{int to, cost;};
typedef pair<int,int> P;
vector<edge> G[MAX_V];
long long int d[MAX_V];
int V,E,s;


main(){
    scanf("%d%d%d",&V,&E,&s);
    for (int i=0; i<E; i++) {
        int from, to, cost;
        scanf("%d", &from);
        scanf("%d", &to);
        scanf("%d", &cost);
        edge edge;
        edge.to = to;
        edge.cost = cost;
        G[from].push_back(edge);
    }
    
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0,s));
    
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v]< p.first) continue;
        for(int i=0; i<G[v].size(); i++){
            edge edge = G[v][i];
            if(d[edge.to]>d[v]+edge.cost){
                d[edge.to]=d[v]+edge.cost;
                que.push(P(d[edge.to],edge.to));
            }
        }
    }
    
    for(int i=0; i<V;i++){
        if(d[i]==INF)printf("INF\n");
        else printf("%lld\n",d[i]);
    }
}

