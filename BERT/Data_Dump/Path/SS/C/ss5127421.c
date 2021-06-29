#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
// const int INF = 1001001001;
const int mod = 1000000007;

struct Edge{
    int to; //次の辺番号
    int cost;// 次の辺までのコスト
    Edge(int to, int cost){
        (*this).to = to;
        (*this).cost = cost;
    }
};

using Graph = vector<vector<Edge>>;
using P = pair<ll,int>;
const ll INF = 1LL << 60;

void dijkstra(Graph &g, int r, vector<ll> &dis){
    priority_queue<P,vector<P>,greater<P>> pq;
    dis.at(r) = ll(0);
    pq.emplace(dis.at(r),r);
    while(!pq.empty()){
        P p = pq.top();pq.pop();
        int v = p.second;
        if(dis.at(v) < p.first) continue;
        for(auto &e : g.at(v)){
            if(dis.at(e.to) > dis.at(v) + e.cost){
                dis.at(e.to) = dis.at(v) + e.cost;
                pq.emplace(dis.at(e.to),e.to);
            }
        }
    }
}

int main(){
    int V,E,r;
    cin >> V >> E >> r;
    Graph g(V);
    vector<ll> dis(V,INF);
    rep(i,E){
        int s,t,d;
        cin >> s >> t >> d;
        g.at(s).emplace_back(t,d);
    }
    dijkstra(g,r,dis);
    for(auto &x : dis){
        if(x == INF){
            cout << "INF" << endl;
            continue;
        }
        cout << x << endl;
    }
}
