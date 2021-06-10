#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const ll INF = 1e16;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cout << a[i] << " "; cout << "\n"; }
template<class T> void verr(const vector<T>& v){ for(auto& a : v) cout << a << " "; cout << "\n"; }
ll dbgt = 1; void err() { cout << "passed " << dbgt++ << "\n"; }
template<class H, class... T> void err(H&& h,T&&... t){ cout<< h << (sizeof...(t)?" ":"\n"); if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//
template <typename T>
struct dijkstra{
    using P = pair<T, ll>;
    const T inf = numeric_limits<T>::max();
    vector<vector<pair<ll,T>>> G;
    vector<ll> beforev;
    vector<T> dist;
    ll N, start;
    priority_queue<P, vector<P>, greater<P>> pq;

    dijkstra(ll n) : N(n) {
        G.resize(n), beforev.assign(n, -1), dist.assign(n, inf);
    }

    void add_edge(ll u, ll v, T cost){
        G[u].emplace_back(v, cost);
    }

    void init(ll s){
        start = s;
        fill(beforev.begin(), beforev.end(), -1), fill(dist.begin(), dist.end(), inf);
        dist[start] = 0, pq.emplace(0, start);
        
        while(!pq.empty()){
            T c; ll from;
            tie(c, from) = pq.top(), pq.pop();
            if (dist[from] < c) continue;
            for(auto& e: G[from]){
                ll to; T cost;
                tie(to, cost) = e;
                if(dist[to]>dist[from]+cost){
                    dist[to] = dist[from] + cost;
                    beforev[to] = from;
                    pq.emplace(dist[to], to);
                }
            }
        }
    }

    vector<ll> get_route(ll goal){
        vector<ll> route;
        ll now = goal;
        while(now!=-1){
            route.emplace_back(now);
            now = beforev[now];
        }
        reverse(route.begin(), route.end());
        return route;
    }
};
int main() {
    init();
    ll N, M, S;
    cin >> N >> M >> S;
    dijkstra<ll> dj(N);
    rep(i,M){
        ll u, v, c;
        cin >> u >> v >> c;
        dj.add_edge(u, v, c);
    }
    dj.init(S);
    rep(i,N){
        ll d = dj.dist[i];
        if(d>=INF){
            cout << "INF" << '\n';
        }
        else{
            cout << d << '\n';
        }
    }
}
