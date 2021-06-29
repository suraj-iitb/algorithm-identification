#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <fstream>

// グラフクラス
class Graph {
public:
	// エッジ
	struct Edge {
		// 接続先のノード番号
		int node;
		// 移動コスト
		int cost;
	};
	// ノード
	struct Node {
		std::vector<Edge> edges;     // 近隣のエッジ
	};
	// コンストラクタ
	Graph(std::istream& in) {
		// ノード数の読み込み
		int n;
		in >> n;
		// ノード用の配列を初期化
		nodes_.resize(n);
		// エッジ数の読み込み
		int e;
		in >> e;
		// 始点の読み込み
		in >> start_;
		for (int i = 0; i < e; ++i) {
			int s, t, u;
			in >> s >> t >> u;
			Edge edge;
			edge.node = t; edge.cost = u;
			nodes_[s].edges.push_back(edge);
		}

	}
	// ノードを取得
	const Node& operator[] (int index) const {
		return nodes_[index];
	}
	// ノード数を取得
	std::size_t node_count() const {
		return nodes_.size();
	}
	// 始点を取得
	int get_start() const {
		return start_;
	}

private:
	// ノード用配列
	std::vector<Node> nodes_;
	// 始点
	int start_;
};

// パス検索クラス
class PathFinder {
	// 距離とノード番号のペア
	using dist_node = std::pair<long, int>;
public:
	// パス検索
	static std::vector<long> find_path(const Graph& graph) {
		// 最大値
		const auto inf = 2147483647L;
		//const auto inf = (float)std::numeric_limits<float>::max();
		// 経路情報
		std::vector<dist_node> dist_nodes(graph.node_count(), { inf, -1 });
		// プライオリティキュー
		std::priority_queue<dist_node, std::vector<dist_node>, std::greater<dist_node>> queue;
		// コストの配列
		std::vector<long> costs;
		// 開始ノードをキューに登録
		int start = graph.get_start();
		dist_nodes[start] = { 0, -1 };
		queue.push({ 0, start });
		// キューにデータがあるか？
		while (!queue.empty()) {
			// 先頭のノードをキューから取り出す
			const auto front = queue.top(); queue.pop();
			const auto front_g = front.first;
			const auto front_node = front.second;
			// キュー内のデータよりも経路情報の合計距離が小さい？
			if (dist_nodes[front_node].first < front_g) continue; //キュー内のデータは最短距離ではないので無視

            // 周辺のノードを取得
			for (const auto& node : graph[front_node].edges) {
				// コストを格納
				const auto g = dist_nodes[front_node].first + node.cost;
				// 合計距離が小さい場合は最短経路としてキューに登録
				if (dist_nodes[node.node].first > g) {
					// 経路情報を保存
					dist_nodes[node.node] = { g, front_node };
					// キューに登録
					queue.push({ g, node.node });
				}
			}
		}
		for (auto node : dist_nodes) {
			if (node.first == inf) {
				costs.push_back(-1);
				continue;
			}
			costs.push_back(node.first);
		}
		return costs;
	}
};

int main() {
	Graph graph(std::cin);
	auto costs = PathFinder::find_path(graph);
	for (auto cost : costs) {
		if (cost == -1) {
			std::cout << "INF" << std::endl;
			continue;
		}
		std::cout << cost << std::endl;
	}
	return 0;
}
