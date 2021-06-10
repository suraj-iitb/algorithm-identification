
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define veci vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vec>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))


using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
//template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
//template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
    for(T& x:vec) is >> x;
    return is;
}
const ll INF=1e10+100;
const ll white=0;
const ll gray=1;
const ll black=2;

vector<pll> m[100005]; 

ll v,r;

void dijkstra(){
    priority_queue<pll> PQ;
    ll color[v];
    ll d[v];
    rep(i,v){
        d[i]=INF;
        color[i]=white;
    }
    d[r]=0;
    PQ.push(make_pair(0,r));
    color[r]=gray;
    while(!PQ.empty()){
        pll f=PQ.top();
        PQ.pop();
        ll u=f.second;
        color[u]=black;
        if(d[u]<f.first*(-1)) continue;
        for(ll j=0;j<m[u].size();j++){
            ll v=m[u][j].first;
            if(color[v]==black) continue;
            if(d[v]>d[u]+m[u][j].second){
                d[v]=d[u]+m[u][j].second;
                PQ.push(make_pair(d[v]*(-1),v));
                color[v]=gray;
            }
        }
    }
    rep(i,v){
        if(d[i]==INF){
            cout << "INF" << endl;
        }
        else{
            cout << d[i] << endl;
        }
    }
}

int main()
{
    ll e;
    cin >> v >> e >> r;
    rep(i,e){
        ll s;
        ll t;
        ll c;
        cin >> s >> t >> c;
        m[s].push_back(make_pair(t,c));
    }
    dijkstra();
} 
