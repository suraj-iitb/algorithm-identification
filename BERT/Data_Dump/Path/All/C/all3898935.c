#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
//constexpr int INF = 1001001001;
constexpr ll INF = 1001001001001001001ll;
constexpr double EPS = 1e-10;
using number = long long;


using Matrix = vector<vector<number>>;

void warshall_floyd(int V, Matrix &g) {
    rep(k, V) {
        rep(i, V) {
            rep(j, V) {
                if (g[i][k] == INF || g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main() {
    int V, E; cin >> V >> E;
    Matrix G(V, vector<number>(V, INF));
    rep(i, V) G[i][i] = 0;
    rep(i, E) {
        int s, t; ll d;
        cin >> s >> t >> d;
        G[s][t] = d;
    }

    warshall_floyd(V, G);

    rep(i, V) {
        if (G[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    rep(i, V) {
        rep(j, V) {
            if (j > 0) cout << " ";
            if (G[i][j] == INF) cout << "INF";
            else cout << G[i][j] ;
        }
        cout << endl;
    }

}
