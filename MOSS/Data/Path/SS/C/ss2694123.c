#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits>


//グラフクラス
class Graph {
public:
	//エッジ
	struct Edge {
		//接続先のノード番号
		int node;
		//移動コスト
		int cost;
	};
	//ノード
	struct Node {
		//近隣のノード
		std::vector<Edge> edges;
	};
	//コンストラクタ
	Graph(std::istream& in) {
		//ノードとエッジ数の読み込み
		int n, e;
		in >> n >> e >> startNode_;
		//ノード用の配列を初期化
		nodes_.resize(n);
		
		//エッジデータの読み込み
		for (int i = 0; i < e; i++) {
			//始点・終点のノード番号を読み込む
			int s, t, c;
			in >> s >> t >> c;
			nodes_[s].edges.push_back({t,c});
		}
	}
	//ノードを取得
	const Node& operator[](int index)const {
		return nodes_[index];
	}
	//ノード数を取得
	std::size_t node_const() const {
		return nodes_.size();
	}
	//スタートノード
	int StartNode()const {
		return startNode_;
	}
private:
	//ノード用配列
	std::vector<Node> nodes_;
	int startNode_;
};

//パス検索クラス
class PathFinder {
	//距離とノード番号のペア
	using dist_node = std::pair<int, int>;
public:
	static std::vector<int> path_cost2(const Graph& graph, int start) {
		std::vector<int> result;

		//最大値
		const auto inf = std::numeric_limits<int>::max();
		//経路情報                          数                  初期値
		std::vector<dist_node> dist_nodes(graph.node_const(), { inf,-1 });
		//プライオリティキュー                               小さいほうからとるようになる
		std::priority_queue<dist_node, std::vector<dist_node>, std::greater<dist_node>> queue;
		//開始ノードをキューに登録
		dist_nodes[start] = { 0,-1 };
		queue.push({ 0,start });
		//キューにデータがあるか?
		while (!queue.empty()) {
			//先頭ノードをキューから取り出す
			const auto front = queue.top(); queue.pop();
			const auto front_g = front.first;
			const auto front_node = front.second;

			//キュー内のデータよりも経路情報の合計距離が小さい?
			if (dist_nodes[front_node].first < front_g) continue; //キュー内のデータは最短距離ではないので無視
																  //周辺のノードを取得
			for (const auto& edge : graph[front_node].edges) {
				//合計距離を求める(移動コストは1.0とする)
				const auto g = dist_nodes[front_node].first + edge.cost;
				//合計距離が小さい場合は最短経路としてキューに登録
				if (dist_nodes[edge.node].first > g) {
					//経路情報を保存
					dist_nodes[edge.node] = { g,front_node };
					//キューに登録
					queue.push({ g,edge.node });
				}
			}
		}

		for (int i = 0; i < graph.node_const(); i++) {
			if (dist_nodes[i].first == inf) {
				result.push_back(-1);
			}
			else {
				result.push_back(dist_nodes[i].first);
			}
		}
		return result;
	}

	static std::vector<int> path_cost(const Graph& graph, int start) {
		std::vector<int> result;
		for (int i = 0; i < graph.node_const(); i++) {
			if (start == i) {
				result.push_back(0);
				continue;
			}
			bool get = false;
			//最大値
			const auto inf = std::numeric_limits<float>::max();
			//経路情報                          数                  初期値
			std::vector<dist_node> dist_nodes(graph.node_const(), { inf,-1 });
			//プライオリティキュー                               小さいほうからとるようになる
			std::priority_queue<dist_node, std::vector<dist_node>, std::greater<dist_node>> queue;
			//開始ノードをキューに登録
			dist_nodes[start] = { 0.0f,-1 };
			queue.push({ 0.0f,start });
			//キューにデータがあるか?
			while (!queue.empty()) {
				//先頭ノードをキューから取り出す
				const auto front = queue.top(); queue.pop();
				const auto front_g = front.first;
				const auto front_node = front.second;
				//ゴールについたか？
				if (front_node == i) {
					result.push_back(dist_nodes[i].first);
					get = true;
					break;
				}
				//キュー内のデータよりも経路情報の合計距離が小さい?
				if (dist_nodes[front_node].first < front_g) continue; //キュー内のデータは最短距離ではないので無視
																	  //周辺のノードを取得
				for (const auto& edge : graph[front_node].edges) {
					//合計距離を求める(移動コストは1.0とする)
					const auto g = dist_nodes[front_node].first + edge.cost;
					//合計距離が小さい場合は最短経路としてキューに登録
					if (dist_nodes[edge.node].first > g) {
						//経路情報を保存
						dist_nodes[edge.node] = { g,front_node };
						//キューに登録
						queue.push({ g,edge.node });
					}
				}
			}
			if (get)continue;
			//経路が見つからない場合は空のパスを返す
			result.push_back(-1);
		}

		return result;
	}

	static int path_cost(const Graph& graph, int start, int end) {
		if (start == end)return 0;
		//最大値
		const auto inf = std::numeric_limits<float>::max();
		//経路情報                          数                  初期値
		std::vector<dist_node> dist_nodes(graph.node_const(), { inf,-1 });
		//プライオリティキュー                               小さいほうからとるようになる
		std::priority_queue<dist_node, std::vector<dist_node>, std::greater<dist_node>> queue;
		//開始ノードをキューに登録
		dist_nodes[start] = { 0.0f,-1 };
		queue.push({ 0.0f,start });
		//キューにデータがあるか?
		while (!queue.empty()) {
			//先頭ノードをキューから取り出す
			const auto front = queue.top(); queue.pop();
			const auto front_g = front.first;
			const auto front_node = front.second;
			//ゴールについたか？
			if (front_node == end) {
				return dist_nodes[end].first;
			}
			//キュー内のデータよりも経路情報の合計距離が小さい?
			if (dist_nodes[front_node].first < front_g) continue; //キュー内のデータは最短距離ではないので無視
																  //周辺のノードを取得
			for (const auto& edge : graph[front_node].edges) {
				//合計距離を求める(移動コストは1.0とする)
				const auto g = dist_nodes[front_node].first + edge.cost;
				//合計距離が小さい場合は最短経路としてキューに登録
				if (dist_nodes[edge.node].first > g) {
					//経路情報を保存
					dist_nodes[edge.node] = { g,front_node };
					//キューに登録
					queue.push({ g,edge.node });
				}
			}
		}
		//経路が見つからない場合は空のパスを返す
		return -1;
	}
};


int main() {
	Graph graph(std::cin);
	std::vector<int> n = PathFinder::path_cost2(graph, graph.StartNode());
	//for (int i = 0; i < graph.node_const(); i++) {
	//	//int n = PathFinder::path_cost(graph, graph.StartNode(), i);
	//	if (n == -1) {
	//		std::cout << "INF" << std::endl;
	//	}
	//	else {
	//		std::cout << n << std::endl;
	//	}
	//}

	for (int i = 0; i < n.size(); i++) {
		if (n[i] == -1) {
			std::cout << "INF" << std::endl;
		}
		else {
			std::cout << n[i] << std::endl;
		}
	}
	
	return 0;
}
