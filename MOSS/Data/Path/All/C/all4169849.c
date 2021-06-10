#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

bool contain(set<P> &s, P a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;


void print_line(vector<string> &line) {
    if (line.size() == 0ll) {
        cout << endl;
        return;
    }
    for (ll i = 0; i < line.size(); i++) {
        cout << line[i];
        if (i == line.size() - 1) cout << endl;
        else cout << ' ';
    }
}

typedef priority_queue<long long, vector<long long>, greater<long long>> PQ_ASK;
struct Edge {
    ll to, cost;
};


class Dijkstra {
    ll vector_count;

    vector<ll> distances;


public:
    vector<vector<Edge>> edges;

    Dijkstra(ll n) {
        vector_count = n;
        distances.resize(n, INF);
        edges.resize(n);
    }

    void insertTowWay(ll from, ll to, ll cost) {
        edges[from].push_back({to, cost});
        edges[to].push_back({from, cost});
    }

    void insert(ll from, ll to, ll cost) {
        edges[from].push_back({to, cost});
    }

    void dijkstra(ll k) {
        distances[k] = 0;  // 始点sへの最短距離は0

        priority_queue<P, vector<P>, greater<P>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
        que.push(P(0, k));
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;  // 更新した頂点の中で距離が最小の頂点v
            if (distances[v] < p.first) {
                continue;
            }
            for (auto e : edges[v]) {  // 頂点vから出る辺eを走査
                if (distances[e.to] > distances[v] + e.cost) {
                    distances[e.to] = distances[v] + e.cost;
                    que.push(P(distances[e.to], e.to));
                }
            }
        }
    }

    ll distance(ll to) {
        return distances[to];
    }

};;


void warshall_floyd(int n, vector<vector<ll>> &distances) {
    for (int k = 0; k < n; k++) {       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                if (distances[i][j] == INF && (distances[i][k] == INF || distances[k][j] == INF)) {
                    distances[i][j] = INF;
                } else {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
    }
}

string to_string2(ll n) {
    std::ostringstream stm;
    stm << n;
    return stm.str();
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<ll>> distances(v, vector<ll>(v, INF));
    rep(i, v) distances[i][i] = 0;

    rep(i, e) {
        ll s, t, d;
        cin >> s >> t >> d;

        distances[s][t] = d;
    }

    warshall_floyd(v, distances);
    {
        vector<vector<ll>> check = distances;
        warshall_floyd(v, check);
        if (check != distances) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }

    }
    rep(i, v) {
        vector<string> ans;
        rep(j, v) {
            ll now = distances[i][j];
            if (now >= INF) ans.push_back("INF");
            else ans.push_back(to_string2(now));
        }
        print_line(ans);
    }

}



