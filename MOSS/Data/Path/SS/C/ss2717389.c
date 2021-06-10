#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
    int source, target, distance;
};

struct Node {
    int vertex, weight;
    bool operator > (const Node& node) const {
        return weight > node.weight;
    }
};


int main()
{
    int n_vertices, n_edges, source_node;
    cin >> n_vertices >> n_edges >> source_node;
    vector< vector<Edge> > adjlist(n_vertices);

    for (int i = 0; i < n_edges; ++i) {
        int source, target, distance;
        cin >> source >> target >> distance;
        adjlist[source].emplace_back(Edge{source, target, distance});
    }

    int visited = 0;
    vector<int> closed(n_vertices, numeric_limits<int>::max());
    priority_queue<Node, vector<Node>, greater<Node> > open;

    open.push(Node{source_node, 0});
    while (visited != n_vertices && !open.empty()) {
        auto node = open.top();
        open.pop();
        if (closed[node.vertex] != numeric_limits<int>::max()) continue;
        for (auto edge : adjlist[node.vertex]) {
            int child = edge.target;
            int distance = edge.distance;
            open.push(Node{child, node.weight + distance});
        }
        closed[node.vertex] = node.weight;
        visited++;
    }

    for (auto weight : closed) {
        if (weight == numeric_limits<int>::max()) {
            cout << "INF";
        } else {
            cout << weight;
        }
        cout << endl;
    }
}



