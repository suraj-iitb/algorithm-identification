// Author: Shusuke Ueda
// AOJ GRL_1_A (Single Source Shortest Path)

#include <iostream>
#include <limits>
#include <vector>
#include <queue>

namespace graph {
    template <typename T>
    class Graph {
        int n;
        std::vector<std::vector<int>> to;
        std::vector<std::vector<T>> cost;

        T inf = std::numeric_limits<T>::max() / 2;

      public:
        Graph(int init_n): n(init_n) {
            to.assign(n, std::vector<int>(0));
            cost.assign(n, std::vector<T>(0));
        }

        void add_directed_edge(int u, int v, T c) {
            to[u].push_back(v);
            cost[u].push_back(c);
        }
        void add_undirected_edge(int u, int v, T c) {
            add_directed_edge(u, v, c);
            add_directed_edge(v, u, c);
        }

        T get_inf() {
            return inf;
        }

        std::vector<T> single_source_shortest_path(int start) {
            std::vector<T> res;
            res.assign(n, inf);
            res[start] = 0;
            auto comp = [](const std::pair<int, T> u, const std::pair<int, T> v) -> bool {
                return u.second > v.second;
            };
            std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, decltype(comp)> que(comp);
            que.push(std::make_pair(start, 0));
            while (!que.empty()) {
                auto pos = que.top();
                que.pop();
                for (int i = 0; i < to[pos.first].size(); i++) {
                    int next = to[pos.first][i];
                    T next_cost = cost[pos.first][i];
                    if (pos.second + next_cost < res[next]) {
                        res[next] = res[pos.first] + next_cost;
                        que.push(std::make_pair(next, res[next]));
                    }
                }
            }
            return res;
        }
        void print_single_source_shortest_path(int start) {
            auto res = single_source_shortest_path(start);
            for (int i = 0; i < n; i++) {
                if (res[i] == inf) {
                    std::cout << "INF" << std::endl ;
                } else {
                    std::cout << res[i] << std::endl;
                }
            }
        }
    };
}

using lint = int_fast64_t;

int main() {
    int v, e, r;
    std::cin >> v >> e >> r;
    graph::Graph<lint> g(v);
    for (int i = 0; i < e; i++) {
        int s, t;
        lint d;
        std::cin >> s >> t >> d;
        g.add_directed_edge(s, t, d);
    }

    g.print_single_source_shortest_path(r);

    return 0;
}
