#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    private:
        vector<int> parent;
    public:
        UnionFind(int n) {
            parent.resize(n, -1);
        }
        int root(int x) {
            int p = parent[x];
            if (p < 0) {
                return x;
            }
            return parent[x] = root(p);
        }
        void unite(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
                if (parent[x] > parent[y]) {
                    swap(x, y);
                }
                parent[x] += parent[y];
                parent[y] = x;
            }
        }
        bool same(int x, int y) {
            return root(x) == root(y);
        }
        int size(int x) {
            x = root(x);
            return -parent[x];
        }
};

struct Graph {
    public:
        struct Edge {
            int from, to, cost;
            bool operator < (const Edge &rhs) const {
                return cost < rhs.cost;
            }
        };
        int INF;
    protected:
        int n;
        vector<vector<Edge>> adj_list;
        vector<bool> visited;
        vector<int> indeg;
    public:
        Graph(int _n) {
            n = _n;
            INF = 2e9;
            adj_list.resize(n, vector<Edge>(0));
            visited.resize(n, false);
            indeg.resize(n, 0);
        }
        virtual void add(int from, int to, int cost) {
            adj_list[from].push_back({from, to, cost});
            indeg[to]++;
        }
        void dfs(int cur) {
            visited[cur] = true;
            for (Edge e : adj_list[cur]) {
                if (visited[e.to]) {
                    continue;
                }
                dfs(e.to);
            }
        }
};

struct _Graph : Graph {
    _Graph(int _n) : Graph(_n) {}
    void dijkstra(int start, vector<int> &dist) {
            dist.resize(n, INF);
            dist[start] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({dist[start], start});
            while (not pq.empty()) {
                int cur = pq.top().second;
                pq.pop();
                for (Edge e : adj_list[cur]) {
                    if (dist[e.to] > dist[cur] + e.cost) {
                        dist[e.to] = dist[cur] + e.cost;
                        pq.push({dist[e.to], e.to});
                    }
                }
            }
        }
    bool bellman_ford(int start, vector<int> &dist) {
        dist.resize(n, INF);
        dist[start] = 0;
        for (int i = 0; i < n; i++) {
            for (int cur = 0; cur < n; cur++) {
                for (Edge e : adj_list[cur]) {
                    if (not visited[e.to]) {
                        continue;
                    }
                    if (dist[e.to] > dist[cur] + e.cost) {
                        dist[e.to] = dist[cur] + e.cost;
                        if (i == n - 1) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool warshall_floyd(vector<vector<int>> &dist) {
        dist.resize(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
            for (Edge e : adj_list[i]) {
                dist[i][e.to] = e.cost;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] == INF or dist[k][j] == INF) {
                        continue;
                    }
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    if (i == j and dist[i][j] < 0) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void prim(vector<int> &weight) {
        weight.resize(n, INF);
        weight[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({weight[0], 0});
        while (not pq.empty()) {
            int cur = pq.top().second;
            pq.pop();
            visited[cur] = true;
            for (Edge e : adj_list[cur]) {
                if (visited[e.to]) {
                    continue;
                }
                if (weight[e.to] > e.cost) {
                    weight[e.to] = e.cost;
                    pq.push({weight[e.to], e.to});
                }
            }
        }
    }
    void topological(vector<int> &sorted) {
            queue<int> q;
            for(int i = 0; i < n; i++) {
                if (indeg[i] == 0) {
                    q.push(i);
                }
            }
            while (not q.empty()) {
                int cur = q.front();
                q.pop();
                sorted.push_back(cur);
                for (Edge e : adj_list[cur]) {
                    indeg[e.to]--;
                    if (indeg[e.to] == 0) {
                        q.push(e.to);
                    }
                }
            }
        }
};

struct Network {
    public:
        struct Edge {
            int to, cap, rev;
        };
        int INF;
    protected:
        int n;
        vector<vector<Edge>> adj_list;
        vector<bool> visited;
    public:
        Network(int _n) {
            n = _n;
            INF = 1e9;
            adj_list.resize(n, vector<Edge>(0));
            visited.resize(n, false);
        }
        void add(int from, int to, int cap) {
            adj_list[from].push_back({to, cap, (int)adj_list[to].size()});
            adj_list[to].push_back({from, 0, (int)adj_list[from].size() - 1});
        }
        int dfs(int cur, int sink, int flow) {
            if (cur == sink) {
                return flow;
            }
            visited[cur] = true;
            for (Edge &e : adj_list[cur]) {
                if (visited[e.to] or e.cap == 0) {
                    continue;
                }
                int neck = dfs(e.to, sink, min(flow, e.cap));
                if (neck > 0) {
                    e.cap -= neck;
                    adj_list[e.to][e.rev].cap += neck;
                    return neck;
                }
            }
            return 0;
        }
        int max_flow(int source, int sink) {
            int flow = 0;
            while (true) {
                fill(visited.begin(), visited.end(), false);
                int f = dfs(source, sink, INF);
                flow += f;
                if (f == 0) {
                    return flow;
                }
            }
            return 0;
        }
};

struct Tree : Graph {
    private:
        int log_n, root;
        vector<int> parent, deapth;
        vector<vector<int>> ancestor;
        void dfs(int cur, int deap) {
            visited[cur] = true;
            deapth[cur] = deap;
            for (Edge e : adj_list[cur]) {
                if (not visited[e.to]) {
                    dfs(e.to, deap + 1);
                }
            }
        }
        void setDeapth() {
            for (int i = 0; i < n; i++) {
                if (parent[i] == -1) {
                    root = i;
                    break;
                }
            }
            dfs(root, 0);
        }
    public:
        Tree(int _n) : Graph(_n) {
            parent.resize(n, -1);
            deapth.resize(n, 0);
            log_n = 0;
            while (_n > 1) {
                _n /= 2;
                log_n++;
            }
            ancestor.resize(log_n + 1, vector<int>(n, -1)); // ancestor[k][i]は節点iの親を2^k回辿った節点(祖先)
        }
        void add(int from, int to, int cost) override {
            Graph::add(from, to, cost);
            parent[to] = from;
        }
        void doubling() {
            for (int k = 0; k <= log_n; k++) {
                for (int i = 0; i < n; i++) {
                    if (k == 0) {
                        ancestor[k][i] = parent[i];
                    } else {
                        if (ancestor[k - 1][i] != -1) {
                            ancestor[k][i] = ancestor[k - 1][ancestor[k - 1][i]];
                        }
                    }
                }
            }
            setDeapth(); // DFSにより節点を求める
            /* for (int i = 0; i < n; i++) { // 二分探索により節点を求める
                int &deap = deapth[i];
                int j = i;
                for (int k = log_n; k >= 0; k--) {
                    if (ancestor[k][j] != -1) {
                        j = ancestor[k][j];
                        deap += 1<<k;
                    }
                }
            } */
        }
        int LCA(int u, int v) {
            int diff = deapth[u] - deapth[v];
            if (diff != 0) {
                if (diff < 0) {
                    swap(u, v);
                    diff *= -1;
                }
                for (int k = 0; k <= log_n; k++) {
                    if (diff & (1<<k)) {
                        u = ancestor[k][u];
                    }
                }
            }
            if (u == v) {
                return u;
            }
            for (int k = log_n; k >= 0; k--) {
                if (ancestor[k][u] != ancestor[k][v]) {
                    u = ancestor[k][u];
                    v = ancestor[k][v];
                }
            }
            return ancestor[0][u];
        }
};

void dijkstra() { // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    int n, m, s;
    cin >> n >> m >> s;
    _Graph G(n);
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        G.add(from, to, cost);
    }
    vector<int> dist;
    G.dijkstra(s, dist);
    for (int i = 0; i < n; i++) {
        if (dist[i] == G.INF) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}

void bellman_ford() { // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    int n, m, s;
    cin >> n >> m >> s;
    _Graph G(n);
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        G.add(from, to, cost);
    }
    G.dfs(s);
    vector<int> dist;
    bool is_negative = G.bellman_ford(s, dist);
    if (is_negative) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == G.INF) {
                cout << "INF" << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
    }
}

void warshall_floyd() { // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    int n, m;
    cin >> n >> m;
    _Graph G(n);
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        G.add(from, to, cost);
    }
    vector<vector<int>> dist;
    bool is_nagative = G.warshall_floyd(dist);
    if (is_nagative) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) {
                    cout << " ";
                }
                if (dist[i][j] == G.INF) {
                    cout << "INF";
                } else {
                    cout << dist[i][j];
                }
            }
            cout << endl;
        }
    }
}

void prim() { // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    int n, m;
    cin >> n >> m;
    _Graph G(n);
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        G.add(from, to, cost);
        G.add(to, from, cost);
    }
    vector<int> weight;
    G.prim(weight);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += weight[i];
    }
    cout << sum << endl;
}

void kruskal() { // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    int n, m;
    cin >> n >> m;
    UnionFind UF(n);
    vector<Graph::Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges[i] = {from, to, cost};
    }
    sort(edges.begin(), edges.end());
    int sum = 0;
    for (Graph::Edge e : edges) {
        if (not UF.same(e.from, e.to)) {
            UF.unite(e.from, e.to);
            sum += e.cost;
        }
    }
    cout << sum << endl;
}

void disjoint_set() { // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    int n, q;
    cin >> n >> q;
    UnionFind UF(n);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            UF.unite(x, y);
        } else if (com == 1) {
            cout << UF.same(x, y) << endl;
        }
    }
}

void topological() { // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
    int n, m;
    cin >> n >> m;
    _Graph G(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        G.add(from, to, 0);
    }
    vector<int> sorted;
    G.topological(sorted);
    for (int i = 0; i < n; i++) {
        cout << sorted[i] << endl;
    }
}

void LCA() { // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    int n;
    cin >> n;
    Tree tree(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            tree.add(i, c, 0);
        }
    }
    tree.doubling();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << tree.LCA(u, v) << endl;
    }
}

void max_flow() { // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    int n, m;
    cin >> n >> m;
    Network G(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        G.add(u, v, c);
    }
    int ans = G.max_flow(0, n - 1);
    cout << ans << endl;
}

int main() {
    dijkstra();
}
