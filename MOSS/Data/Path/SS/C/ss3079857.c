#include "bits/stdc++.h"
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define vi vector<int>
#define pb push_back
#define INF 999999999
//#define INF (1LL<<59)
 
//verified AOJ GRL_1
#define MAX_V 100000
struct edge{int to,cost;};
vector<edge> G[MAX_V];
 
void dijkstra(int s, vector<int> &d){
    priority_queue< pii,vector<pii>,greater<pii> > que;
    rep( i,d.size() )d[i]=INF;
    d[s] = 0;
    que.push( pii(0,s) );
     
    while( que.size() ){
        pii p=que.top();
        que.pop();
         
        int v=p.second;
        if(d[v]<p.first)continue;
         
        rep(i,G[v].size()){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(pii(d[e.to],e.to));
            }
        }
    }
}
 
 
int main(){
    int v,e,s;
    cin>>v>>e>>s;
    rep(i,e){
        int a,b,c;
        cin>>a>>b>>c;
        G[a].pb(edge{b,c});
    }
     
    vi d(v);
    dijkstra(s,d);
     
    rep(i,v){
        if(d[i]==INF)cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
}
