#include <vector>
#include <queue>
#include <iostream>
#include <climits>

void out(int n){
	std::cout << "line = " << n << std::endl;
}
class Edge{
public:
	int node, weight;
	Edge(const int &n = 0, const int &w = 0):node(n), weight(w){};
};
class Node{
public:
	int node, weight;
	Node(const int &n, const int &w):node(n), weight(w){};
	bool operator<(const Node &other) const {return weight > other.weight;}
	bool operator>(const Node &other) const {return other.weight > weight;}
	bool operator==(const Node &other) const {return weight == other.weight;}
	bool operator<=(const Node &other) const {return weight >= other.weight;}
	bool operator>=(const Node &other) const {return other.weight >= weight;}

};
int main(){
	int v, e, r;
	std::cin >> v >> e >> r;
	std::vector<std::vector<Edge>> edges(v);
	std::vector<int> weight(v, INT_MAX);
	for (auto i = 0; i < e; ++i){
		int s, t, d;
		std::cin >> s >> t >> d;
		edges.at(s).push_back(Edge(t, d));
	}
	for (auto i = 0; i < v; ++i){
		edges.at(i).push_back(Edge(i, 0));
	}
	std::priority_queue<Node> queue;
	queue.push(Node(r, 0));
	while (queue.size() != 0){
		weight.at(queue.top().node) = queue.top().weight;
		for (Edge edge : (edges.at(queue.top().node))){
			if (weight.at(edge.node) > edge.weight + queue.top().weight){
				queue.push(Node(edge.node, edge.weight + queue.top().weight));
			}
		};
		while ((queue.top().weight >= weight.at(queue.top().node)) and (queue.size() > 0)){
			//out(100);out(queue.top().node);out(queue.top().weight);
			queue.pop();
		}
	}
	for (auto w : weight){
		if (w == INT_MAX){
			std::cout << "INF\n";
		}else{
			std::cout << w << "\n";
		}
	}
}
