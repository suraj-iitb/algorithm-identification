#include<bits/stdc++.h>
using namespace std;
long long INF = 1e18;

struct Edge{
    int to;
    int cost;
};
using P = pair<int,int>;
int main(){
    
    int v,e,r;
    cin>>v>>e>>r;
    vector<Edge>g[v+100];
    for(int i=0; i<e; i++){
        int s,t,b;
        cin>>s>>t>>b;
        g[s].push_back(Edge{t,b});
    }

    priority_queue<P,vector<P>,greater<P>>que;

    long long d[v+100];
    for(int i=0; i<v; i++){
        d[i]=INF;
    }
    
    d[r] = 0;
    que.push(P(0,r));
     while(que.size()) {

        P p = que.top(); que.pop();

        long long cost = p.first;
        long long v = p.second;

        if(d[v] < cost) continue;
        for(int i = 0; i < g[v].size(); i++) {

            Edge e = g[v][i];

            if(d[e.to] > d[v] + e.cost) {

                d[e.to] = d[v] + e.cost;

                que.push(P(d[e.to], e.to));

            }

        }
    }
    for(int i =0 ; i<v;i++ ){
        if(d[i] !=1e18){
        cout<<d[i]<<endl;
        }else{
            cout<<"INF"<<endl;
        }
    
    }

    return 0;
}
