#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct WarshallFloyd {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<vector<T>> dp;
    WarshallFloyd(int n) : n(n), dp(n, vector<T>(n, INF)) {
        for (int i = 0; i < n; i++) dp[i][i] = 0;
    }
    void relax(int k) {
        for (int i = 0; i < n; i++) if (dp[i][k] != INF)
            for (int j = 0; j < n; j++) if (dp[k][j] != INF)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }
    bool build() {
        for (int k = 0; k < n; k++) relax(k);
        return !has_negative_cycle();
    }
    void add_edge(int u, int v, T cost) {
        dp[u][v] = min(dp[u][v], cost);
        for (int k : {u, v}) relax(k);
    }
    bool has_negative_cycle() {
        for (int i = 0; i < n; i++) if (dp[i][i] < 0) return true;
        return false;
    }
    friend ostream& operator<<(ostream& os, WarshallFloyd<T> &wf) {
        for (int i = 0; i < wf.n; i++) for (int j = 0; j < wf.n; j++) {
            if (wf.dp[i][j] == wf.INF) os << "INF"; else os << wf.dp[i][j];
            os << " \n"[j == wf.n - 1];
        }
        return os;
    }
};

int main() {
    int n, m; cin >> n >> m;
    WarshallFloyd<long long> wf(n);
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        wf.add_edge(a, b, c);
    }
    if (wf.has_negative_cycle()) return !(cout << "NEGATIVE CYCLE" << endl);
    cout << wf;
    return 0;
}

