#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline void out(T a){ cout << a << '\n'; }
void YN(bool ok){if(ok) cout << "Yes" << endl; else cout << "No" << endl;}
//void YN(bool ok){if(ok) cout << "YES" << endl; else cout << "NO" << endl;}


const ll INF=1e18;
const int mx=200005;

struct edge{ll to,cost;};


struct PP{
    ll min_d,vert;
};

bool operator> (const PP &p1, const PP &p2){
    return p1.min_d > p2.min_d;
};


class Dijkstra{
public:
    ll n;//頂点数,辺数
    V<V<edge>> G;
    V<ll> d;
    V<ll> pr;

    explicit Dijkstra(ll sz_n){
        n=sz_n;
        G.resize(sz_n);
        d.resize(sz_n);
        pr.resize(sz_n);
    }

    void add_edge(ll from,ll to,ll cost){
        G[from].push_back((edge){to,cost});
        //G[to].push_back((edge){from,cost});//有向辺の場合は削除
    }

    void exe(ll s){//頂点sからの最短距離
        priority_queue<P,vector<P>,greater<P>> que;
        rep(i,n) d[i]=INF;
        d[s]=0;
        que.push(P(0,s));//pair...first->最短距離、second->頂点

        while(!que.empty()){
            P p=que.top();que.pop();
            ll v=p.sc;
            if(d[v]<p.ft) continue;
            for(int i=0;i<(int)G[v].size();i++){
                edge e=G[v][i];
                if(d[e.to]>d[v]+e.cost){
                    d[e.to]=d[v]+e.cost;
                    que.push(P(d[e.to],e.to));
                    pr[e.to]=v;
                }
            }
        }
    }

    ll dist_to(ll t){
        return d[t];
    }

    //頂点tへの最短路
    vector<ll> get_path(ll t){
        vector<ll> path;
        for(;t!=-1;t=pr[t]) path.push_back(t);//tがsになるまでprev[t]をたどっていく
        reverse(all(path));
        return path;
    }

};

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,m,r;
    cin>>n>>m>>r;
    Dijkstra ds(n);
    rep(i,m){
        ll s,t,d;
        cin>>s>>t>>d;
        ds.add_edge(s,t,d);
    }
    ds.exe(r);
    rep(i,n){
        ll ans=ds.dist_to(i);
        if(ans==INF) out("INF");
        else out(ans);
    }
}
