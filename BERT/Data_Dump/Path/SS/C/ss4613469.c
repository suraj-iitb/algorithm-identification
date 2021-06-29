#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,int> pl;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXV=100000;
const int MAXE=200000;
const ll INF=1e18;

struct edge{
    int to;
    ll cost;
};

int v,e,r;
vector<vector<edge> > G(MAXV);
vector<ll> d(MAXV,INF);

void dijkstra(int r){
    priority_queue<pl,vector<pl>,greater<pl> > que;
    d[r]=0;
    que.push(pl(0,r));
    while(!que.empty()){
        pl p=que.top();que.pop();
        ll a=p.first;int v=p.second;
        if(d[v]<a) continue;
        for(int i=0;i<(int)G[v].size();i++){
            edge ed=G[v][i];
            if(d[ed.to]>d[v]+ed.cost){
                d[ed.to]=d[v]+ed.cost;
                que.push(pl(d[ed.to],ed.to));
            }
        }
    }
}

int main(){
    cin>>v>>e>>r;
    for(int i=0;i<e;i++){
        int s,t,d;
        cin>>s>>t>>d;
        G[s].push_back(edge{t,d});
    }
    dijkstra(r);
    for(int i=0;i<v;i++){
        if(d[i]==INF) cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
    return 0;
}
