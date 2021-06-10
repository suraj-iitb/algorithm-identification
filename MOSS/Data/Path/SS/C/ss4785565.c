#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll LLINF = 1e+18;

using P = pair<ll,int>;
using Edge = pair<int,ll>;
vector<vector<Edge>> G;
vector<ll> d;

int V,E,r;

void dijkstra( int s ) {
    priority_queue<P,vector<P>,greater<P>> que;
    d[s] = 0;
    que.push(P(0,s));
     
    while( que.size() ){
        P p = que.top(); que.pop();
        ll dis = p.first;
        int v = p.second;
        if ( d[v] < dis ) continue;
        for ( int i = 0; i < G[v].size(); ++i){
            Edge e = G[v][i];
            int nv = e.first;
            ll ndis = e.second;
            if ( d[nv] > d[v] + ndis ){
                d[nv] = d[v] + ndis;
                que.push(P(d[nv],nv));
            }
        }
    }
}

int main() {
    cin >> V >> E >> r;
    G.resize(V);
    d.resize(V,LLINF);
    
    REP(i,E){
        int s,t,d;
        cin >> s >> t >> d;
        G[s].push_back(Edge(t,d));
    }
    
    dijkstra(r);
    
    REP(i,V){
        if ( d[i] == LLINF ) cout << "INF" << endl;
        else cout << d[i] << endl;
    }

    
    
    return 0;
}

