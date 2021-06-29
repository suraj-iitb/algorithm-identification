#include <bits/stdc++.h>
#define int long long

struct edge { int to; int cost; };
using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using ge = vector<vector<edge>>;
using gi = vector<vector<int>>;
// using mint = modint1000000007;
// using mint = modint998244353;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ")
#define print1(v) cout << fixed << setprecision(10) << v << "\n"
#define print2(v1, v2) cout << fixed << setprecision(10) << v1 << " " << v2 << "\n"
#define print3(v1, v2, v3) cout << fixed << setprecision(10) << v1 << " " << v2 << " " << v3 << "\n"
#define printvi(v, n) REP(iiii, n) { cout << v[iiii]; delim(iiii, n); }
#define printvii(v, h, w) REP(iiiii, h) { printvi(v[iiiii], w); }

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn = 100000;
int n, m, r;
ge G(maxn);
vi mindist(maxn);

void printge() {
    REP(i, n) {
        cout << (i+1) << ":";
        for(auto v : G[i]) cout << " " << (v.to+1) << "(" << v.cost << ")";
        cout << "\n";
    }
}

// O(|E|log|V|)
void dijkstra() {
    mindist.assign(n, inf);
    priority_queue<P, vector<P>, greater<P>> pq;
    mindist[r] = 0;
    pq.emplace(mindist[r], r);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (mindist[v] < p.first) continue;
        for (auto &e : G[v]) {
            if (mindist[e.to] > mindist[v] + e.cost) {
                mindist[e.to] = mindist[v] + e.cost;
                pq.emplace(mindist[e.to], e.to);
            }
        }
    }
}

signed main () {
	cin.tie(0);
    ios::sync_with_stdio(false);

    // https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
    cin >> n >> m >> r;
    REP(i, m) {
        edge e;
        int s; cin >> s >> e.to >> e.cost;
        G[s].push_back(e);
    }

    dijkstra();

    REP(i, n) {
        if (mindist[i] == inf) {
            cout << "INF\n";
        } else {
            cout << mindist[i] << "\n";
        }
    }
}


// O(|V|^2)
// dist が大きくなって効率が悪い
// void dijkstra() {
//     REP(i, n) mindist[i] = dist[r][i];

//     bool visited[n];
//     REP(i, n) visited[i] = false;
//     visited[r] = true;
//     REP(i, n-1) {
//         int mm = inf;
//         int v = -1;
//         REP(j, n) {
//             if (!visited[j] && mindist[j] < mm) {
//                 v = j;
//                 mm = mindist[j];
//             }
//         }
//         if (v == -1) return;
//         visited[v] = true;
//         REP(j, n) {
//             if (!visited[j]) {
//                 mindist[j] = min(mindist[j], mindist[v] + dist[v][j]);
//             }
//         }
//     }
// }
