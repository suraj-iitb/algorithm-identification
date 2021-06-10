//verify http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
using cost_t=int;

struct Edge {
    int from, to;
    cost_t cost;
    Edge(int from, int to, cost_t cost) : from(from), to(to), cost(cost) {}
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

const cost_t INF=1e9;
void spfa(int s,Graph& g,vector<cost_t>& d){
    int n=g.size();
    d.assign(n,INF);
    vector<int> used(n);
    used[s]=true;
    d[s]=0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int v = que.front(); que.pop();
        used[v]=false;
        for(auto& e:g[v]){
            cost_t tmp = d[v]+e.cost;
            if(!used[e.to] && tmp<d[e.to]){
                que.push(e.to);
                used[e.to]=true;                
            }
            d[e.to]=min(d[e.to],tmp);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V,E,r;
    cin>>V>>E>>r;
    Graph g(V);
    for(int i=0;i<E;i++){
        int s,t,d;
        cin>>s>>t>>d;
        g[s].push_back(Edge{s,t,d});
    }
    vector<cost_t> d;
    spfa(r,g,d);
    for(int i=0;i<V;i++){
        if(d[i]<INF) cout<<d[i]<<"\n";
        else cout<<"INF"<<"\n";
    }
    
    return 0;
}

