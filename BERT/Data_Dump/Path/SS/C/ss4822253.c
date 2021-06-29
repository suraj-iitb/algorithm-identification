#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Dijkstra{
    struct edge{
        int to; T cost;
        edge(int to,T cost):to(to),cost(cost){}
        bool operator<(const edge &e) const {
            return cost>e.cost;
        }
    };
    vector<vector<edge>> G;
    vector<T> dp;
    vector<int> pre;
    Dijkstra(int n):G(n),dp(n),pre(n){}
    void add_edge(int u,int v,T c){
        G[u].emplace_back(v,c);
    }
    void build(int s){
        int n=G.size();
        fill(dp.begin(),dp.end(),numeric_limits<T>::max());
        fill(pre.begin(),pre.end(),-1);
        priority_queue<edge> pq;
        dp[s]=0;
        pq.emplace(s,dp[s]);
        while(!pq.empty()){
            auto p=pq.top(); pq.pop();
            int v=p.to;
            if (dp[v]<p.cost) continue;
            for (auto e:G[v]){
                if (dp[v]+e.cost<dp[e.to]){
                    dp[e.to]=dp[v]+e.cost;
                    pre[e.to]=v;
                    pq.emplace(e.to,dp[e.to]);
                }
            }
        }
    }
    vector<int> restore(int t){
        vector<int> res;
        if (pre[t]<0) return res;
        while(~t){
            res.emplace_back(t);
            t=pre[t];
        }
        reverse(res.begin(),res.end());
        return res;
    }
    T operator[](int to){return dp[to];}
};

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A

void GRL_1_A(){
    int V,E,r; cin >> V >> E >> r;

    Dijkstra<long long> D(V);
    for (int i=0;i<E;++i){
        int s,t,d; cin >> s >> t >> d;
        D.add_edge(s,t,d);
    }

    D.build(r);
    for (int i=0;i<V;++i){
        if (D[i]>1e18) cout << "INF" << '\n';
        else cout << D[i] << '\n';
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    GRL_1_A();
}
