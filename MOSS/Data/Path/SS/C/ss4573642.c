#include<bits/stdc++.h>
using namespace std;
#define INF -1000000000

struct edge{
    int from;
    int to;
    int cost;
};

int V,E,r;
edge G[510000];
int D[110000];

void bellman_ford(int s){
    int i;
    bool update;
    edge e;

    for(i=0;i<V;i++)D[i]=INF;
    D[s]=0;
    while(true){
        update=false;
        for(i=0;i<E;i++){
            e=G[i];
            if(D[e.from]!=INF && (D[e.to]==INF || D[e.to]>D[e.from]+e.cost)){
                D[e.to]=D[e.from]+e.cost;
                update=true;
            }
        }
        if(!update)break;
    }
}

int main(){
    int i;
    cin>>V>>E>>r;
    for(i=0;i<E;i++){
        cin>>G[i].from>>G[i].to>>G[i].cost;
    }

    bellman_ford(r);

    for(i=0;i<V;i++){
        if(D[i]!=INF)cout<<D[i]<<"\n";
        else cout<<"INF\n";
    }
}

