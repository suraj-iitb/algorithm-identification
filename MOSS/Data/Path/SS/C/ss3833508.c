#include<bits/stdc++.h>
using namespace std;

// 辺を表す構造体
struct edge{
    int to;
    long long cost;
};

// キューに入れる頂点を表す構造体
struct node{
    int id;
    long long cost;

    bool operator<(const node& rhs) const {
        return cost > rhs.cost;
    }
};

constexpr long long INF = 1LL << 61;

void dijkstra(int s, vector<long long>& cost, const vector< vector<edge> >& g){
    cost.resize(g.size());
    fill(cost.begin(), cost.end(), INF);
    cost[s] = 0;
    priority_queue<node> que;
    que.push({s, 0LL});

    while(!que.empty()){
        node now = que.top();
        que.pop();
        if(cost[now.id] < now.cost){
            continue;
        }
        for(auto& e : g[now.id]){
            if(cost[e.to] > now.cost + e.cost){
                cost[e.to] = now.cost + e.cost;
                que.push({e.to, now.cost + e.cost});
            }
        }
    }

    return;
}

int main(){
    int v, e, r;
    cin >> v >> e >> r;

    vector< vector<edge> > g(v);
    for(int i = 0 ; i < e ; ++i){
        int s, t;
        long long d;
        cin >> s >> t >> d;
        g[s].push_back({t, d});
    }

    vector<long long> cost;
    dijkstra(r, cost, g);

    for(int i = 0 ; i < v ; ++i){
        if(cost[i] < INF){
            cout << cost[i] << endl;
        }else{
            cout << "INF" << endl;
        }
    }

    return 0;
}
