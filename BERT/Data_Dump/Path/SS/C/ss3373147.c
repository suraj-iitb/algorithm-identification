
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repr(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<(int)(n);i++)
#define INF 99999999999999
#define MAX_V 100010

    /*Solve*/
struct vertex{
    vertex(ll arg_to,ll arg_cost){
        to=arg_to;
        cost=arg_cost;
    }
    ll to,cost;
};
ll V,E,r;
vector<vertex> G[MAX_V];
ll d[MAX_V];

void dijksra(ll s){
    priority_queue<P,vector<P>,greater<P>> que;
    fill(d,d+V,INF);
    d[s] = 0;
    que.push(P(0,s));   //first:最短距離,second:頂点の番号
    while(!que.empty()){
        P p = que.top();que.pop();
        ll v = p.second;
        if(d[v] < p.first) continue;
        for(ll i=0;i<G[v].size();i++){
            vertex e=G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main(){
    cin >> V >> E >> r;
    rep(i,E){
        ll s,t,d;
        cin >> s >> t >> d;
        G[s].push_back(vertex(t,d));
    }
    dijksra(r);
    rep(i,V){
        if(d[i]==INF)cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}
