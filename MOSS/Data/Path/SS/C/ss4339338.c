#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,ll>;
const ll inf = 1e15;
const int mod = 10007;

int main() {
    int v, e, s;
    cin >> v >> e >> s;
    vector<vector<P>> cost(v);
    rep(i,e) {
        int s, t, d;
        cin >> s >> t >> d;
        cost[s].push_back(P(t,d));
    }
    vector<ll> d(v,inf);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(0,s));
    while (!q.empty()) {
        P e = q.top(); q.pop();
        int v = e.second;
        if (e.first > d[v]) continue;
        for (int i = 0; i < cost[v].size(); i++) {
            P edge = cost[v][i];
            if (chmin(d[edge.first],d[v]+edge.second)) q.push(P(d[edge.first],edge.first));
        }
    }
    rep(i,v) {
        if (d[i] == inf) {
            cout << "INF" << endl;
            continue;
        }
        cout << d[i] << endl;
    }
}
