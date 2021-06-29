#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<deque>
#include<bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T&a , T b){ if(a<b){ a=b; return true; } else{ return false; } }
template<class T> inline bool chmin(T&a , T b){ if(a>b){ a=b; return true; } else{ return false; } } 

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

struct Edge{
    ll to;
    ll cost;
};

vector<vector<Edge> > G;
ll dis[100005];
ll V,E,r;

void dijkstra(ll r){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dis,dis+V,INF);
    dis[r] = 0;
    que.push(P(0,r));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        for(auto e : G[v]){
            if(dis[e.to] > dis[v]+e.cost){
                dis[e.to] = dis[v] + e.cost;
                que.push(P(dis[e.to],e.to));
            }
        }
    }
}

int main(){
    cin >> V >> E >> r;
    G.resize(V);
    for(int i=0;i<E;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        struct Edge x = { b,c };
        G[a].push_back(x);
    }

    dijkstra(r);
    rep(i,V){
        if(dis[i]==INF){
            cout << "INF" << endl;
            continue;
        }
        cout << dis[i] << endl;
    }
}
