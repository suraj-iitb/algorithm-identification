#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const long long LINF = (1LL<<60);
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
using pl = pair<ll,ll>;
using pi = pair<int,int>;
ll v,e,r;
vector<pi> g[100100];

vector<ll> dijkstra(ll s){
    priority_queue<pl, vector<pl>, greater<pl>> q;
    //(cost,address)
    vector<ll> dist(v,LINF);
    dist[s] = 0;
    q.push(pl(dist[s],s));

    while(!q.empty()){
        auto p = q.top(); q.pop();
        ll d = p.first;
        ll from = p.second;
        if(dist[from] < d)continue;
        for(auto c:g[from]){
            ll to = c.first;
            ll di = c.second;
            if(dist[from] + di < dist[to]){
                dist[to] = dist[from] + di;
                q.push(pl(dist[to],to));
            }
        }
    }
    return dist;
}

signed main(){
	//cout << fixed << setprecision(10);
	cin >> v >> e >> r;
    rep(i,0,e){
        int a,b,c; cin >> a >> b >> c;
        g[a].push_back(make_pair(b,c));//0-indexed
    }
    auto dist = dijkstra(r);
    rep(i,0,v){
        if(dist[i] == LINF)cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
	return 0;
}
