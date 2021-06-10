#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1e9+7LL;
const ll INF = 1e18;
const ll MAX_V = 100010ll;
 
struct edge { ll to, cost; };
vector<edge> G[MAX_V];
ll d[MAX_V];
 
int main() {
    ll V, E, r; cin >> V >> E >> r;
    rep(i, E){
        ll s, t, d; cin >> s >> t >> d;
        G[s].push_back({t,d});
    }
 
    priority_queue<P, vector<P>, greater<P> > que1;
    fill(d, d + V, INF);
    d[r] = 0;
    que1.push(P(0, r));
    while (!que1.empty()) {
        P p = que1.top(); que1.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;
        ll s = G[v].size();
        for (ll i = 0; i < s; i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que1.push(P(d[e.to], e.to));
            }
        } 
    }
    rep(i, V){
        if(d[i]==INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}
