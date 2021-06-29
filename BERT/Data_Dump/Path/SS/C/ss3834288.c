#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

constexpr i64 INF = 1e9;

struct Edge{
    int from, to;
    i64 cost;
};

using Graph = vector<vector<Edge>>;

int main(){
    int v, e, r;
    cin >> v >> e >> r;
    Graph graph(v, vector<Edge>());
    for(int i=0;i<e;++i){
        int s, t;
        i64 d;
        cin >> s >> t >> d;
        graph[s].push_back({s, t, d});
    }
    vector<i64> mini(v, INF);
    mini[r] = 0;
    priority_queue<pair<int, i64>> que;
    que.push({r, 0});
    while(!que.empty()){
        auto cur = que.top(); que.pop();
        for(auto e: graph[cur.first]){
            i64 cost = cur.second + e.cost;
            if(mini[e.to] < cost)continue;
            mini[e.to] = cost;
            que.push({e.to, cost});
        }
    }
    for(int i=0;i<v;++i){
        if(mini[i] >= INF){
            cout << "INF";
        }else{
            cout << mini[i];
        }
        cout << endl;
    }

    return 0;
}

