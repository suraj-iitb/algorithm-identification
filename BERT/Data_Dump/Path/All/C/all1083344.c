// グラフ

// 隣接リスト

// cycle を検出 ⇔ 強連結成分の個数をチェック

#include<vector>
#include<queue>
#include<functional>
#include<cfloat>
#include<tuple>
#include<set>
#include<stack>

const double INF = DBL_MAX / 3.0;

// Edge
class Edge {
public:
    Edge(const int f, const int t, const double w) :from_(f), to_(t), weight_(w) {}
    int from() const {return from_;}
    int to() const {return to_;}
    double weight() const {return weight_;}
    bool operator<(const Edge& e) const {
        if(from() != e.from()) return from() < e.from();
        if(to() != e.to()) return to() < e.to();
        return weight() < e.weight();
    }
private:
    int from_, to_;
    double weight_;
};

// Graph
class Graph {
public:
    explicit Graph(int s) :size_(s) {edge_.resize(s);}

    int size() const {return size_;}
    const std::vector<Edge>& edge(const int v) const {return edge_[v];}

    void add(const Edge& e);
    void add(const int from, const int to, const double weight);
    double Dijkstra(const int start, const int goal) const;
    std::vector<double> Dijkstra_all(const int start) const;
    double BellmanFord(const int start, const int goal) const;
    std::vector<double> BellmanFord_all(const int start) const;
    std::vector<std::vector<double>> WarshallFloyd() const;
    bool cut_vertex(const int v, const std::set<int>& visited = std::set<int>()) const;
    std::vector<std::vector<int>> Kosaraju() const;

private:
    void cut_vertex_reachability(const int from, std::set<int>& visited) const;
    void Kosaraju_dfs_postorder(const int from, std::vector<bool>& visited, std::stack<int>& order) const;
    std::vector<int> Kosaraju_dfs_decompose(const std::vector<std::vector<Edge>>& reverse_edge, const int from, std::vector<bool>& visited) const;

    int size_;
    std::vector<std::vector<Edge>> edge_;
};

// implements
void Graph::add(const Edge& e) {edge_[e.from()].push_back(e);}

void Graph::add(const int from, const int to, const double weight) {edge_[from].push_back(Edge(from, to, weight));}

double Graph::Dijkstra(const int start, const int goal) const {
    enum {COST, VERTEX};
    typedef std::tuple<double, int> Node;
    std::vector<bool> visited(size(), false);
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
    q.push(Node(0, start));
    while(!q.empty()) {
        double cost = std::get<COST>(q.top());
        int from = std::get<VERTEX>(q.top());
        q.pop();
        if(from == goal) return cost;
        if(visited[from]) continue;
        visited[from] = true;
        for(const auto& e: edge(from)) q.push(Node(cost + e.weight(), e.to()));
    }
    return INF;
}

std::vector<double> Graph::Dijkstra_all(const int start) const {
    enum {COST, VERTEX};
    typedef std::tuple<double, int> Node;
    std::vector<double> result(size(), INF);
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
    q.push(Node(0, start));
    while(!q.empty()) {
        double cost = std::get<COST>(q.top());
        int from = std::get<VERTEX>(q.top());
        q.pop();
        if(result[from] <= cost) continue;
        result[from] = cost;
        for(const auto& e: edge(from)) q.push(Node(cost + e.weight(), e.to()));
    }
    return result;
}

double Graph::BellmanFord(const int start, const int goal) const {
    std::vector<double> distance(size(), INF);
    distance[start] = 0;
    for(int step = 0; step <= size(); ++step) {
        for(int from = 0; from < size(); ++from) {
            for(const auto& e: edge(from)) {
                if(distance[from] + e.weight() >= distance[e.to()]) continue;
                if(step == size()) return INF;
                distance[e.to()] = distance[from] + e.weight();
            }
        }
    }
    return distance[goal];
}

std::vector<double> Graph::BellmanFord_all(const int start) const {
    std::vector<double> distance(size(), INF);
    distance[start] = 0;
    for(int step = 0; step <= size(); ++step) {
        for(int from = 0; from < size(); ++from) {
            for(const auto& e: edge(from)) {
                if(distance[from] + e.weight() >= distance[e.to()]) continue;
                if(step == size()) return std::vector<double>();
                distance[e.to()] = distance[from] + e.weight();
            }
        }
    }
    return distance;
}

std::vector<std::vector<double>> Graph::WarshallFloyd() const {
    std::vector<std::vector<double>> result(size(), std::vector<double>(size(), INF));
    for(const auto& edge: edge_) for(const auto& e: edge) result[e.from()][e.to()] = e.weight();
    for(int i = 0; i < size(); ++i) result[i][i] = 0;
    for(int k = 0; k < size(); ++k) for(int i = 0; i < size(); ++i) for(int j = 0; j < size(); ++j)
        result[i][j] = std::min(result[i][j], result[i][k] + result[k][j]);
    return result;
}

bool Graph::cut_vertex(const int v, const std::set<int>& visited) const {
    std::set<int> dup = visited;
    for(const auto& e: edge(v)) {
        if(dup.count(e.to())) continue;
        cut_vertex_reachability(e.to(), dup);
        return dup.size() != size();
    }
    return dup.size() != size();
}
void Graph::cut_vertex_reachability(const int from, std::set<int>& visited) const {
    visited.insert(from);
    for(const auto& e: edge(from)) if(!visited.count(e.to())) cut_vertex_reachability(e.to(), visited);
}

std::vector<std::vector<int>> Graph::Kosaraju() const {
    std::vector<std::vector<int>> result;

    std::vector<bool> visited(size(), false);
    std::stack<int> order;
    for(int v = 0; v < size(); ++v) if(!visited[v]) Kosaraju_dfs_postorder(v, visited, order);

    std::vector<std::vector<Edge>> reverse_edge(size(), std::vector<Edge>());
    for(int v = 0; v < size(); ++v) for(const auto& e: edge(v)) reverse_edge[e.to()].push_back(Edge(e.to(), e.from(), e.weight()));

    visited = std::vector<bool>(size(), false);
    while(!order.empty()) {
        int v = order.top();
        order.pop();
        if(visited[v]) continue;
        result.push_back(Kosaraju_dfs_decompose(reverse_edge, v, visited));
    }
    return result;
}
void Graph::Kosaraju_dfs_postorder(const int from, std::vector<bool>& visited, std::stack<int>& order) const {
    visited[from] = true;
    for(const auto& e: edge(from)) if(!visited[e.to()]) Kosaraju_dfs_postorder(e.to(), visited, order);
    order.push(from);
}
std::vector<int> Graph::Kosaraju_dfs_decompose(const std::vector<std::vector<Edge>>& reverse_edge, const int from, std::vector<bool>& visited) const {
    std::vector<int> result;
    result.push_back(from);
    visited[from] = true;
    for(const auto& e: reverse_edge[from]) {
        if(visited[e.to()]) continue;
        std::vector<int> add = Kosaraju_dfs_decompose(reverse_edge, e.to(), visited);
        result.insert(result.end(), add.begin(), add.end());
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////

// 無向木の最遠点対
//     ある頂点から最も遠い点を u とし, u から最も遠い点を v とすると (u, v) が最遠点対
// 有向だとダメ && cycle があると死ぬ
// ！！！！遅い！！！！
std::tuple<double, int> diameter_of_unoriented_tree_dfs(const Graph& g, const int previous, const int current) {
    std::tuple<double, int> result(0.0, current);
    for(const auto& e: g.edge(current)) {
        if(e.to() == previous) continue;
        double w; int v;
        std::tie(w, v) = diameter_of_unoriented_tree_dfs(g, current, e.to());
        w += e.weight();
        if(std::get<0>(result) < w) result = std::make_tuple(w, v);
    }
    return result;
}
double diameter_of_unoriented_tree(const Graph& g) {
    double w; int v;
    std::tie(w, v) = diameter_of_unoriented_tree_dfs(g, -1, 0);
    std::tie(w, v) = diameter_of_unoriented_tree_dfs(g, -1, v);
    return w;
}

// DFS tree を作成
//     tarjan's algorithm?
//     Algorithmics: theory and practice, Gilles Brassard and Paul Bratley
void dfs_tree(const Graph& g, const int previous, const int current, int& timer, std::vector<int>& prenum, std::vector<int>& parent, std::vector<int>& lowest) {
    prenum[current] = timer;
    lowest[current] = timer;
    parent[current] = previous;
    for(const auto& e: g.edge(current)) {
        if(prenum[e.to()] == -1) {
            dfs_tree(g, current, e.to(), ++timer, prenum, parent, lowest);
            lowest[current] = std::min(lowest[current], lowest[e.to()]);
        } else if(e.to() != previous) {
            lowest[current] = std::min(lowest[current], prenum[e.to()]);
        }
    }
}
// 連結グラフの cut vertex の集合を返す
std::set<int> cut_vertex(const Graph& g) {
    std::vector<int> prenum(g.size(), -1);
    std::vector<int> parent(g.size(), -1);
    std::vector<int> lowest(g.size(), 1000000000);
    int timer = 0;
    dfs_tree(g, -1, 0, timer, prenum, parent, lowest);
    std::set<int> result;
    int count = 0;
    for(const auto& p: parent) if(p == 0) count++;
    if(count >= 2) result.insert(0);
    for(int v = 1; v < g.size(); ++v) {
        if(parent[v] == 0) continue;
        if(prenum[parent[v]] <= lowest[v]) result.insert(parent[v]);
    }
    return result;
}
// 無向連結グラフの bridge の集合を返す
std::set<Edge> bridge(const Graph& g) {
    std::vector<int> prenum(g.size(), -1);
    std::vector<int> parent(g.size(), -1);
    std::vector<int> lowest(g.size(), 1000000000);
    int timer = 0;
    dfs_tree(g, -1, 0, timer, prenum, parent, lowest);
    std::set<Edge> result;
    for(int v = 0; v < g.size(); ++v)
        for(const auto& e: g.edge(v))
            if(prenum[e.from()] < lowest[e.to()]) result.insert(Edge(std::min(e.from(), e.to()), std::max(e.from(), e.to()), e.weight()));
    return result;
}

// start を含む連結成分における最小全域木
Graph Prim(const Graph& g, const int start = 0) {
    struct Compare {
      bool operator()(const Edge& lhs, const Edge& rhs) const {
        if(lhs.weight() != rhs.weight()) return lhs.weight() > rhs.weight();
        if(lhs.from() != rhs.from()) return lhs.from() > rhs.from();
        return lhs.to() > rhs.to();
      }
    };
    Graph result(g.size());
    std::set<int> visited;
    std::priority_queue<Edge, std::vector<Edge>, Compare> q;
    visited.insert(start);
    for(const auto& e: g.edge(start)) q.push(e);
    while(!q.empty()) {
        Edge edge = q.top();
        q.pop();
        if(visited.count(edge.to())) continue;
        visited.insert(edge.to());
        result.add(edge);
        for(const auto& e: g.edge(edge.to())) q.push(e);
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for(int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        g.add(s, t, d);
    }
    auto list = g.WarshallFloyd();
    bool ok = true;
    for(int i = 0; i < g.size(); ++i) if(list[i][i] < 0) ok = false;
    if(ok) {
        for(int i = 0; i < g.size(); ++i) {
            for(int j = 0; j < g.size(); ++j) {
                if(j != 0) cout << " ";
                if(list[i][j] == INF) cout << "INF";
                else cout << (int) list[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "NEGATIVE CYCLE" << endl;
    }
}
