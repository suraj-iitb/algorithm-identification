#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a <= b) {
        a = b;
        return true;
    }
    return false;
}

struct Edge{
    ll to,cost;
};
template<typename T>
struct dijkstra{
    vector<T> dist;
    vector<int> prev;
    dijkstra(vector<vector<Edge>> &g,int s){
        dist=vector<T>(g.size(),inf);
        prev=vector<int>(g.size(),-1);
        using pi=pair<T,int>;
        priority_queue<pl,vector<pi>,greater<pi>> que;
        dist[s]=0;
        que.emplace(dist[s],s);
        while(!que.empty()){
            T cost;int idx;
            tie(cost,idx)=que.top();que.pop();
            if(dist[idx]<cost)continue;
            for(auto &e:g[idx]){
                T ncost=cost+e.cost;
                if(dist[e.to]<=ncost)continue;
                prev[e.to]=idx;
                dist[e.to]=ncost;
                que.emplace(dist[e.to],e.to);
            }
        }
    }
    vector<int> get_path(int t){//到達できない場合、return=t;
        vector<int> path;
        for (int cur = t; cur != -1; cur = prev[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main(){
    ll n,m,r;cin >> n >> m >>r;
    vector<vector<Edge>> g(n);
    while(m--){
        ll s,t,d;cin >> s >> t >>d;
        g[s].pb({t,d});
    }
    dijkstra<ll> d(g,r);
    for(auto p:d.dist){
        if(p==inf)cout << "INF" <<endl;
        else cout << p <<endl;
    }
}   
