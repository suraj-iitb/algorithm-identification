#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define Clear(a) a = decltype(a)()
#define all(a) a.begin(),a.end()
#define vec vector
typedef long long ll;
typedef pair<ll,ll> p;
//const ll big=998244353;
const ll big=1000000007LL;
const ll INF=1000000000000000000LL;//1e18
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
if(x<y)return x;
else return y;
}
ll expm(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (expm(x,y-1)*x)%big;
    ll t=expm(x,y/2);
    return (t*t)%big;
}
ll exp(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||y==0)return x;
    if(y%2==1)return exp(x,y-1)*x;
    ll t=exp(x,y/2);
    return t*t;
}
ll inv(ll x){
    return expm(x,big-2);
}

struct edge{
    ll to;
    ll cost;
};
struct graph{
    ll v;
    vec<vec<edge>> g;
    vec<ll> d;
    graph(ll n) : v(n),g(n),d(n,INF) {}
    void add(ll a,ll b,ll c){
        edge e;
        e.to=b,e.cost=c;
        g[a].emplace_back(e);
    }

    void dijkstra(ll s){
        d[s]=0;
        priority_queue<p,vec<p>,greater<p>> que;
        que.push(p(0,s));//距離,位置(距離でsortされるように)
        while(!que.empty()){
            p now=que.top();que.pop();
            if(now.first>d[now.second])continue;
            for(edge ne : g[now.second]){
                if(ne.cost+now.first<d[ne.to]){
                    d[ne.to]=ne.cost+now.first;
                    que.push(p(d[ne.to],ne.to));
                }
            }
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/

    int n,m,r;cin >> n >> m >> r;
    graph g(n);
    rep(i,m){
        ll s,t,d;cin >> s >> t >> d;
        g.add(s,t,d);
    }
    g.dijkstra(r);
    rep(i,n){
        if(g.d[i]<INF)cout << g.d[i] << endl;

        else cout << "INF" << endl;
    }
}
