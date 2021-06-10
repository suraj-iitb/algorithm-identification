#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<limits>

// 隣接リスト
using weight_graph = std::vector<std::vector<std::pair<size_t, size_t>>>;

int main(){
    
    size_t vertex, edge, root;
    std::cin >> vertex >> edge >> root;

    weight_graph graph(vertex);

    for(size_t i = 0; i < edge; i++){
        size_t s, t, w;
        std::cin >> s >> t >> w;
        graph.at(s).emplace_back(t, w);
    }

    std::vector<size_t> cost(vertex, std::numeric_limits<size_t>::max()); // 添字までのコスト
    std::vector<bool> seen(vertex, false); // 添字に訪れたかどうか
    std::priority_queue<std::pair<size_t, size_t>, // first: 重み, second: 頂点番号
                        std::vector<std::pair<size_t, size_t>>, 
                        std::greater<std::pair<size_t, size_t>>> candidate;

    cost.at(root) = 0; // rootへのコストは0
    candidate.emplace(0, root); // rootを候補へ

    while(!candidate.empty()){ // ダイクストラ
        auto node = candidate.top(); candidate.pop();
        auto v = node.second;

        if(seen.at(v)) continue;
        seen.at(v) = true;

        if(cost.at(v) < node.first) continue; // 小手先の最適化
                                              // (訪れる頂点への最短経路コストが辺の重みより小さい場合最短経路に含まれることはない)

        for(size_t i = 0; i < graph.at(v).size(); i++){
            if(cost.at(v) + graph.at(v).at(i).second < cost.at(graph.at(v).at(i).first)){
                cost.at(graph.at(v).at(i).first) = cost.at(v) + graph.at(v).at(i).second;
                candidate.emplace(cost.at(graph.at(v).at(i).first), graph.at(v).at(i).first);
            }
        }
    }

    for(const auto& e : cost){
        if(e == std::numeric_limits<size_t>::max()){
            std::cout << "INF" << std::endl;
        }else{
            std::cout << e << std::endl;
        }
    }
    
    return 0;
}
