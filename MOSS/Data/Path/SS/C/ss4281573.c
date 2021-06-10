//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1<<30;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};

struct edge{int to; int cost;};
vector<vector<edge>> graph(0);
vector<int> d(0);
const int MAX_dist=1e9;

void init(int n){
    graph.resize(n);
    d.resize(n,MAX_dist);
}

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    d[s]=0;
    que.emplace(0,s);
    while(!que.empty()){
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        rep(i,graph[v].size()){
            edge e=graph[v][i];
            if(d[e.to]>d[v]+e.cost){
            d[e.to]=d[v]+e.cost;
            que.emplace(d[e.to],e.to);
            }
        }
    }
}

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int v,e,r;
    cin>>v>>e>>r;
    init(v);
    int s,t,dd;
    rep(i,e){
        cin>>s>>t>>dd;
        graph[s].push_back({t,dd});
    }
    dijkstra(r);
    rep(i,v){
        if(d[i]==MAX_dist) cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
}
