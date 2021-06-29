#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>

// intの最大値
const static int INF = 2147483647;

class Graph {
public:
	// エッジ
	struct Edge {
		// 接続先のノード番号
		int node;
		// 移動コスト
		int cost;
		// コンストラクタ
		Edge(const int node, const int cost) : node(node), cost(cost) {	}
	};
	// ノード
	struct Node {
		// エッジ
		std::vector<Edge> edges_;
	};

	// コンストラクタ
	Graph(std::istream& in) {
		// 総ノード数の読み込み
		int n;
		in >> n;
		// ノード用配列を初期化
		nodes_.resize(n);

		// 総エッジ数の抽出
		int e;
		in >> e;

		// 開始ノードの抽出
		int start;
		in >> start;
		start_ = start;

		// 1
		// エッジデータの読み込み
		for (int i = 0; i != e; ++i) {
			// 始点・終点のノードの番号を読み込む
			int s, t, c;
			// s 始点ノード, t 近隣ノード, c コスト
			in >> s >> t >> c;
			// ノードに近隣ノードの番号を登録
			nodes_[s].edges_.emplace_back(t, c);
		}
	}

	// ノードを取得
	const Node& operator[](int index) const { return nodes_[index]; }
	// ノード数を取得
	std::size_t node_count() const { return nodes_.size(); }
	// 開始ノードの取得
	int start_node() const { return start_; }

private:
	// ノード用配列
	std::vector<Node> nodes_;
	// 開始ノード
	int start_;
};

class PathFinder {
	// 距離とノード番号のペア
	using dist_node = std::pair<int, int>;

public:
	// パス検索
	static std::vector<std::string> find_path(const Graph& graph) {
		// 初期値を最大値にする
		// 経路情報
		// 始めに個数と番号を指定して作成する
		// { 合計コスト, 親の番号 }
		std::vector<dist_node> dist_nodes(graph.node_count(), { INF, -1 });
		// プライオリティキュー
		// 合計コストが少ないパスを取得する greater<>
		std::priority_queue<dist_node, std::vector<dist_node>, std::greater<dist_node>> queue;
		// 開始ノードをキューに登録
		dist_nodes[graph.start_node()] = { 0, -1 };
		queue.push({ 0, graph.start_node() });
		// キューにデータがあるか？
		while (!queue.empty()) {
			// 先頭ノードをキューから取り出す
			const auto front = queue.top();
			// pop でデータを捨てる
			queue.pop();
			const auto front_g = front.first;
			const auto front_node = front.second;

			// キュー内のデータよりも経路情報の合計距離が小さいか？
			// キュー内のデータは最短距離ではないので無視
			// 情報を毎回更新する
			if (dist_nodes[front_node].first < front_g) continue;
			// 近隣ノードを取得
			// for (const auto& node : graph[front_node].nodes_) 
			for (const auto& edge : graph[front_node].edges_) {
				const auto g = dist_nodes[front_node].first + edge.cost;
				// 親ノードまでのコストの合計値と比較して、値が小さければ更新する
				if (dist_nodes[edge.node].first > g) {
					// 経路情報を保存
					dist_nodes[edge.node] = { g, front_node };
					// キューに登録
					queue.push({ g, edge.node });
				}
			}
		}
		// 経路が見つからない場合でも検索していたパスを返す
		return create_cost(dist_nodes);
	}

private:
	// パスの作成
	static std::vector<std::string> create_path(const std::vector<dist_node>& dist_nodes, int end) {
		std::vector<std::string> path;
		for (int node = end; node != -1; node = dist_nodes[node].second) {
			path.push_back(std::to_string(node));
		}

		return path;
	}

	// コスト一覧の生成
	static std::vector<std::string> create_cost(const std::vector<dist_node>& dist_nodes) {
		std::vector<std::string> path;
		for (int i = 0; i != dist_nodes.size(); ++i) {
			std::string cost = std::to_string((int)dist_nodes[i].first);
			//auto inf = std::numeric_limits<float>::max();
			// 無限値の場合は、INFを表示する
			if (dist_nodes[i].first == INF) cost = "INF";
			path.push_back(cost);
		}

		return path;
	}
};

int main() {
	Graph graph(std::cin);
	auto path = PathFinder::find_path(graph);
	// 経路パスの表示(逆順)
	for (auto node_id : path) {
		std::cout << node_id << std::endl;
	}

	return 0;
}
