#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>
#include <limits>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <numeric>
//#include <tuple>

constexpr long long mod = static_cast<long long>(1e9 + 7);

int main() {
    int V, E;
    std::cin >> V >> E;
    std::vector<std::vector<long long>> dists(V, std::vector<long long>(V, std::numeric_limits<long long>::max()));
    for(int i = 0; i < V; ++i) {
        dists[i][i] = 0;
    }

    while(E--){
        int s, t, w;
        std::cin >> s >> t >> w;
        dists[s][t] = w;
    }

    for(int i = 0;i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            for(int k = 0; k < V; ++k) {
                if(dists[j][i] < std::numeric_limits<long long>::max() && dists[i][k] < std::numeric_limits<long long>::max()) dists[j][k] = std::min(dists[j][k], dists[j][i] + dists[i][k]);
            }
        }
    }

    bool negative = false;
    for(int i = 0; i < V; ++i) {
        if(dists[i][i] < 0) negative = true;
    }

    if(negative) std::cout << "NEGATIVE CYCLE" << std::endl;
    else {
        for(const auto& dist: dists) {
            for(int i = 0; i < dist.size(); ++i){
                if(dist[i] == std::numeric_limits<long long>::max())std::cout << "INF";
                else std::cout << dist[i];
                if(i < dist.size() - 1) std::cout << " ";
            }
            std::cout << "\n";
        }
    }

    std::cout << std::flush;

    return 0;
}

