#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
// typedef pair<int, int> P;
typedef pair<ll, int> P;
typedef vector<int> vi;
typedef vector<P> vp;
typedef vector<ll> vll;

struct edge { int to; ll cost; };

const ll inf = 1e15;
const int MAX_N = 100010;

int N, M;
int s;
vector<edge> G[MAX_N];
ll d[MAX_N];

//s: start
void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> que;   // cost, vertex
    rep(i, N) d[i] = inf;
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        rep(i, G[v].size()) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> N >> M >> s;
    rep(i, M) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        G[a].emplace_back((edge){b, c});
    }

    dijkstra(s);
    rep(i, N) {
        if (d[i] < inf) {
            cout << d[i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }
}
