#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    using VertexId = std::uint32_t;
    using EdgeId = std::uint64_t;
    using EdgeWeight = std::uint64_t;
    using AdjData = std::pair<VertexId, EdgeWeight>;
    using AdjList = std::vector<AdjData>;

    auto n = VertexId(0);
    auto m = EdgeId(0);
    auto start_vertex = VertexId(0);
    std::cin >> n >> m >> start_vertex;

    auto adjacency_list = std::vector<AdjList>(n, AdjList());
    for (auto i_ = 0; i_ < m; ++i_) {
        auto source = VertexId(0);
        auto target = VertexId(0);
        auto weight = EdgeWeight(0);
        std::cin >> source >> target >> weight;

        adjacency_list[source].emplace_back(target, weight);
    }

    const auto invalid_distance = std::numeric_limits<EdgeWeight>::max();
    auto distance = std::vector<EdgeWeight>(n, invalid_distance);
    distance[start_vertex] = EdgeWeight(0);

    auto checked = std::vector<bool>(n);

    auto comp = [](const auto& a, const auto& b) { return a.second > b.second; };
    auto q = std::priority_queue<std::pair<VertexId, EdgeWeight>, std::vector<std::pair<VertexId, EdgeWeight>>,
                                 decltype(comp)>(comp);
    q.emplace(start_vertex, 0);

    while (!q.empty()) {
        const auto next = q.top();
        const auto v = next.first;
        const auto d = next.second;
        q.pop();

        if (checked[v]) continue;

        checked[v] = true;
        distance[v] = d;

        for (const auto& e : adjacency_list[v]) {
            const auto target = e.first;
            const auto weight = e.second;

            if (d + weight >= distance[target]) continue;

            q.emplace(target, d + weight);
        }
    }

    for (const auto& d : distance) {
        if (d == invalid_distance) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << d << std::endl;
        }
    }

    return 0;
}
