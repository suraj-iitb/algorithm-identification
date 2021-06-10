
#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
using P          = pair<long, long>;
const int INF    = 1e9;
const lint LINF  = 1e18;
const double EPS = 1e-10;

int main() {
    lint N, M, start;
    cin >> N >> M >> start;

    struct edge {
        lint to;
        lint cost;
    };

    vector<vector<edge>> edges(N, vector<edge>(0));
    rep(i, M) {
        lint from, to, cost;
        cin >> from >> to >> cost;
        edges[from].push_back(edge({to, cost}));
    }

    vector<lint> distance(N, -1);

    priority_queue<P, vector<P>, greater<P>> q;
    for (int i = 0; i < N; i++) {
        if (i == start) {
            q.push({0, start});
        } else {
            q.push({LINF, i});
        }
    }

    while (!q.empty()) {
        lint min_cost, min_node;
        tie(min_cost, min_node) = q.top(), q.pop();
        if (distance[min_node] != -1) continue;
        distance[min_node] = min_cost;
        for (auto e : edges[min_node]) {
            q.push({distance[min_node] + e.cost, e.to});
        }
    }

    for (int i = 0; i < N; i++) {
        lint d = distance[i];
        if (d == LINF) {
            cout << "INF" << endl;
        } else {
            cout << d << endl;
        }
    }
    return 0;
}
