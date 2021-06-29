#include <bits/stdc++.h>
using namespace std;
using i64=int_fast64_t;
using i32=int_fast32_t; 
using P=pair<i64,i64>;
const i64 MOD=1000000007;
const i64 INF=1000000010;
const i64 LINF=4000000000000000010;
int main(){
    struct edge{i32 to;i64 cost;};
    vector<vector<edge>> G;
    vector<i64> di;
    i32 n,m,st;cin>>n>>m>>st;
    G.resize(n);
    di.resize(n);
    for(i32 i=0;i<m;i++){
        i32 u,v,d;cin>>u>>v>>d;
        G[u].push_back({v,d});
    }
    priority_queue<P,vector<P>,greater<P>> q;
    fill(di.begin(),di.end(),LINF);
    di[st]=0;
    q.push(P(0,st));
    while(!q.empty()){
        i32 v=q.top().second;q.pop();
        for(auto e:G[v]){
            if(di[e.to]<=di[v]+e.cost)continue;
            di[e.to]=di[v]+e.cost;
            q.push(P(di[e.to],e.to));
        }
    }
    for(i32 i=0;i<n;i++){
        if(di[i]==LINF){
            cout<<"INF"<<endl;
            continue;
        }
        cout<<di[i]<<endl;
    }
    return 0;
}   
