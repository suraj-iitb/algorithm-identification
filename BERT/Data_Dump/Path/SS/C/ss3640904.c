#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1

ll mod_add(ll a, ll b) { return (a + b) % MOD; }
ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return a*b % MOD; }

ll n,m,r;

template<class T> 
class DK{
public:
    struct edge{
        ll to;
        T cost;
        edge(ll _to,T _cost):to(_to),cost(_cost){}
    };

    vector<T> d;
    vector<vector<edge>> G;

    DK(ll _n){
        d.resize(_n);
        G.resize(_n);
    }

    //無向辺
    void add_edge(ll from,ll to,T cost){
        G[from].push_back(edge(to,cost));
        // G[to].push_back(edge(from,cost));
    }

    void dijkstra(ll start){
        fill(ALL(d),INF);
        d[start] = 0;

        typedef pair<T,ll> PP;
        priority_queue<PP, vector<PP>, greater<PP>> que;
        que.push(PP(0,start));

        while (!que.empty()){
            PP p = que.top();
            que.pop();
            ll v = p.second;
            T cost = p.first;
            if(cost > d[v])continue;
            rep(i,G[v].size()){
                edge e = G[v][i];
                ll to = e.to;
                T ncost = cost + e.cost;
                if (d[e.to] > ncost){
                    d[e.to] = ncost;
                    que.push(PP(d[e.to],to));
                }
            }
        }
    }
};

int main(){
    cin >> n >> m >> r;
    DK<ll> dk(n);
    rep(i,m){
        ll x,y; 
        ll z;
        cin >> x >> y >> z;
        dk.add_edge(x,y,z);
    }
    dk.dijkstra(r);
    rep(i,n){
        if(dk.d[i] == INF)cout << "INF" << endl;
        else cout << dk.d[i] << endl;
    }
}
