#include <bits/stdc++.h>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (long long i = 0; i < n; i++)
#define RREP(i, n) for (long long i = n - 1, 0 <= i; i--)
#define FOR(i, start, end) for (long long i = start; i < end; i++)
#define RFOR(i, start, end) for (long long i = start - 1; 0 <= i; i--)
#define ALL(a) a.begin(), a.end()
#define MOD(a) a %= 1'000'000'007
using ll = long long;
using namespace std;
const int INF32       = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7        = 1'000'000'007;
const int MOD9        = 1'000'000'009;
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
void print() { std::cout << '\n'; }
template <class H, class... T> void print(H &&head, T &&... args) {
    std::cout << head;
    sizeof...(args) == 0 ? std::cout << "" : std::cout << ' ';
    print(std::forward<T>(args)...);
}
template <class T> void print(std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        i == v.size() - 1 ? std::cout << '\n' : std::cout << ' ';
    }
}
template <class T> void print(std::vector<std::vector<T>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j];
            j == v[i].size() - 1 ? std::cout << '\n' : std::cout << ' ';
        }
    }
}

class Warshall_floyd {
  private:
    int vertex;
    const long long INF = 4'000'000'000'000'000'000;
    vector<vector<long long>> cost;

  public:
    Warshall_floyd(int N) {
        vertex = N;
        cost.resize(N, vector<long long>(N, INF));
        for (int i = 0; i < vertex; i++) {
            cost[i][i] = 0;
        }
    }
    void directed_update(int x, int y, long long weight) {
        cost[x][y] = weight;
    }
    void undirected_update(int x, int y, long long weight) {
        cost[x][y] = weight;
        cost[y][x] = weight;
    }
    void calc() {
        for (int k = 0; k < vertex; k++) {
            for (int i = 0; i < vertex; i++) {
                for (int j = 0; j < vertex; j++) {
                    if (cost[i][k] != INF && cost[k][j] != INF)
                        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }
    // pair 型で返す。first が距離で second が実現可能か
    pair<long long, bool> dist(int x, int y) {
        pair<long long, bool> ans;
        if (cost[x][y] == INF) {
            ans.first  = 0;
            ans.second = false;
        } else {
            ans.first  = cost[x][y];
            ans.second = true;
        }
        return ans;
    }
    bool is_negative() {
        bool ans = false;
        for (int i = 0; i < vertex; i++) {
            if (cost[i][i] < 0) {
                ans = true;
                break;
            }
        }
        return ans;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int v, e;
    cin >> v >> e;
    auto wf = Warshall_floyd(v);
    REP(i, e) {
        int a, b, c;
        cin >> a >> b >> c;
        wf.directed_update(a, b, c);
    }
    wf.calc();
    if (wf.is_negative()) {
        print("NEGATIVE CYCLE");
        return 0;
    }
    vector<vector<string>> ans(v, vector<string>(v));
    REP(i, v) {
        REP(j, v) {
            auto dist = wf.dist(i, j);
            if (dist.second) {
                ans[i][j] = to_string(dist.first);
            } else {
                ans[i][j] = "INF";
            }
        }
    }
    print(ans);

    return 0;
}
