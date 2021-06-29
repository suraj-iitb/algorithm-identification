#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

struct edge {
    int a, b;
    double w;
};

class BellmanFord {    
    int n;
    vector<edge> edges;
    vector<double> d;

public:
    BellmanFord(int n) : n(n) {
        edges = vector<edge>(n);
        d = vector<double>(n, numeric_limits<double>::infinity());
    }

    void addEdge(int a, int b, double w) {
        assert(0 <= a && a < n && 0 <= b && b < n);
        edges.push_back({a, b, w});
        edges.push_back({b, a, w});
    }
    void addArc(int a, int b, double w) {
        assert(0 <= a && a < n && 0 <= b && b < n);
        edges.push_back({a, b, w});
    }

    // return true if has negative loop
    bool run(int a) {
        d[a] = 0;
        for (int i = 0; i < n; i++) {
            bool change = false;
            for (edge e: edges) {
                if (d[e.a] != numeric_limits<double>::infinity()) {
                    if (d[e.b] > d[e.a] + e.w) {
                        d[e.b] = d[e.a] + e.w;
                        change = true;
                    }
                }
            }
            if (!change) {
                return false;
            }
        }
        return true;
    }

    double dist(int a) {
        return d[a];
    }
};

int main() {
    int v, e;
    cin >> v >> e;
    double dist[v][v];
    BellmanFord g(v);
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i != j) {
                dist[i][j] = numeric_limits<double>::infinity();
            } else {
                dist[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g.addArc(a, b, w);
        dist[a][b] = min(dist[a][b], double(w));
    }

    for (int i = 0; i < v; i++) {
        if (g.run(i)) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    }

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    auto format = [](double a) {
        if (a == numeric_limits<double>::infinity()) {
            return "INF"s;
        } else {
            return to_string(i64(a));
        }
    };

    for (int i = 0; i < v; i++) {
        cout << format(dist[i][0]);
        for (int j = 1; j < v; j++) {
            cout << " " << format(dist[i][j]);
        }
        cout << endl;
    }
}