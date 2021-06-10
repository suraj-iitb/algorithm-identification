#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int to, cost;
};

struct St {
    int pos;
    int cost;
    bool operator<(const St& s) const {
        return cost > s.cost;
    }
    St(const int p, const int c) {
        pos = p;
        cost = c;
    }
};

const int N = 100001;
vector<Edge> edge[N];
int visited[N];

int main()
{
    int n, en, s;
    cin >> n >> en >> s;

    for (int i=0; i < en; ++i) {
        int from;
        Edge e;
        cin >> from >> e.to >> e.cost;
        edge[from].push_back(e);
    }

    priority_queue<St> que;
    que.push(St(s, 0));
    fill(visited, visited+N, -1);

    while (!que.empty()) {
        St cur = que.top();
        que.pop();
        if (visited[cur.pos]!=-1) {
            continue;
        }
        visited[cur.pos] = cur.cost;

        for (int i=0; i < edge[cur.pos].size(); ++i) {
            Edge e = edge[cur.pos][i];
            if (visited[e.to] != -1) continue;
            que.push(St(e.to, cur.cost + e.cost));
        }
    }

    for (int i=0; i < n; ++i) {
        if (visited[i] == -1) {
            cout << "INF" << endl;
        }
        else {
            cout << visited[i] << endl;
        }
    }

    return 0;
}
