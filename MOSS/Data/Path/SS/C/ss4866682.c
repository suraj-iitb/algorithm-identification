#include<bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
struct edge{
    int to,cost;
};


int main(){
    int v,e,r;
    cin>>v>>e>>r;
    vector< vector<edge> > G(v);
    for(int i=0;i<e;i++){
        int s;
        edge tmp;
        cin>>s>>tmp.to>>tmp.cost;
        G[s].push_back(tmp);
    }

    vector<bool> visited(v);
    vector<long long> cost(v,INT_MAX);
    cost[r] = 0;
    //自分までの距離の最小値と自分のインデックス
    priority_queue< P, vector<P>, greater<P> > pq;
    pq.push(make_pair(cost[r],r));

    while(!pq.empty()){
        P tmp = pq.top();
        pq.pop();
        if(visited[tmp.second]) continue;
        visited[tmp.second] = true;
        for(int i=0;i<G[tmp.second].size();i++){
            int to = G[tmp.second][i].to;
            int d = G[tmp.second][i].cost;
            if(cost[to]>cost[tmp.second]+d){
                cost[to] = cost[tmp.second]+d;
                pq.push(make_pair(cost[to],to));
            }
        }
    }

    for(int i=0;i<v;i++){
        if(cost[i]==INT_MAX) cout<<"INF"<<endl;
        else cout<<cost[i]<<endl;
    }
    return 0;
}
