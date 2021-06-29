#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct edge{long long to,cost;};
const long long INF=1e17;
const int MAX_V=100000;
int V,E,r;
vector<edge> G[MAX_V];
long long d[MAX_V];
typedef pair<long,long>P;

void dijkstra(int s){
    priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(pair<long,long>(0,s));
    
    while(!que.empty()){
        pair<long,long> p=que.top();que.pop();
        long long v=p.second;
        if(d[v]<p.first)continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(pair<long,long>(d[e.to],e.to));
            }
        }
    }
}

int main(){
    cin>>V>>E>>r;
    int s,t,dist;
    for(int i=0;i<E;i++){
        cin>>s>>t>>dist;
        edge j;
        j.to=t;j.cost=dist;
        G[s].push_back(j);
    }
    //fill(d,d+V,INF);
    //cout<<d[0]<<endl;
    dijkstra(r);
    
    for(int i=0;i<V;i++){
        if(d[i]==INF)cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
    
    return 0;
    
}
