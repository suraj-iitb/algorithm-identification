// Author: Shusuke Ueda
// AOJ GRL_1_C (All Pairs Shortest Path)

#include <iostream>
#include <limits>
#include <vector>

namespace graph {
    template <typename T>
    class AdjacencyListGraph {
        int n;
        std::vector<std::vector<T>> cost;

        T inf = std::numeric_limits<T>::max() / 2;

      public:
        AdjacencyListGraph(int init_n): n(init_n) {
            cost.assign(n, std::vector<T>(n, inf));
            for (int i = 0; i < n; i++) {
                cost[i][i] = 0;
            }
        }

        void add_directed_edge(int u, int v, T c) {
            cost[u][v] = std::min(cost[u][v], c);
        }
        void add_undirected_edge(int u, int v, T c) {
            add_directed_edge(u, v, c);
            add_directed_edge(v, u, c);
        }
        void all_pairs_shortest_path() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (cost[j][i] != inf and cost[i][k] != inf) {
                            cost[j][k] = std::min(cost[j][k], cost[j][i] + cost[i][k]);
                        }
                    }
                }
            }
        }

        T get_inf() {
            return inf;
        }
        bool is_inf(int u, int v) {
            return cost[u][v] == inf;
        }
        T get_cost(int u, int v) {
            return cost[u][v];
        }
        bool has_negative_loop() {
            bool res = false;
            for (int i = 0; i < n; i++) {
                if (cost[i][i] < 0) {
                    res = true;
                    break;
                }
            }
            return res;
        }
        
        friend std::ostream& operator << (std::ostream& os, const AdjacencyListGraph g) {
            for (int i = 0; i < g.n; i++) {
                for (int j = 0; j < g.n; j++) {
                    if (j > 0) {
                        std::cout << " ";
                    }
                    if (g.cost[i][j] == g.inf) {
                        std::cout << "INF";
                    } else {
                        std::cout << g.cost[i][j];
                    }
                }
                if (i < g.n - 1) {
                    std::cout << std::endl;
                }
            }
            return os;
        }
    };
}

using lint = int_fast64_t;

int main() {
    int n, e;
    std::cin >> n >> e;
    graph::AdjacencyListGraph<lint> alg(n);
    for (int i = 0; i < e; i++) {
        int s, t;
        lint d;
        std::cin >> s >> t >> d;
        alg.add_directed_edge(s, t, d);
    }

    alg.all_pairs_shortest_path();

    if (alg.has_negative_loop()) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
    } else {
        std::cout << alg << std::endl;
    }

    return 0;
}
