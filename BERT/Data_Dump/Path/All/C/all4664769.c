#include <vector>

template<typename T>
bool warshall_floyd (std::vector<std::vector<T>> &g, const T &inf) {
    const int n = (int)g.size();
    for (int i = 0; i < n; i++) g[i][i] = T(0);
    bool ret = false;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][k] == inf or g[k][j] == inf) continue;
                if (g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) ret |= (g[i][i] < 0);
    return ret;
}

template<class T>
using matrix = std::vector<std::vector<T>>;


#include <iostream>
constexpr long long inf = (1LL << 60);

int main() {
    int n, m;
    std::cin >> n >> m;
    matrix<long long> g(n, std::vector<long long>(n, inf));

    for (int i = 0; i < m; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        g[s][t] = d;
    }

    bool neg = warshall_floyd(g, inf);

    if (not neg) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == inf) std::cout << "INF" << " \n"[j + 1 == n];
                else std::cout << g[i][j] << " \n"[j + 1 == n];
            }
        }
    } else {
        std::cout << "NEGATIVE CYCLE" << '\n';
    }

    return 0;
}
