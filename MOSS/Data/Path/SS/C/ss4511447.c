#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

typedef pair<int, int> P;

int n, m, r, d[MAX_N];
vector<P> E[MAX_N];

void dijkstra(){
    bool seen[n];
    fill(seen, seen + n, false);
    fill(d, d + n, INT_MAX);
    priority_queue<P> todo;
    d[r] = 0;
    todo.push(P(-1 * d[r], r));
    
    while(!todo.empty()){
        int v = todo.top().second, D = -1 * todo.top().first;
        todo.pop();
        seen[v] = true;
        for(int i = 0; i < E[v].size(); i++){
            int u = E[v][i].first, c = E[v][i].second;
            if(!seen[u] && D + c < d[u]){
                d[u] = D + c;
                todo.push(P(-1 * d[u], u));
            }
        }
    }
}

int main(){
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int s, t, c;
        cin >> s >> t >> c;
        E[s].push_back(P(t, c));
    }
    dijkstra();
    for(int i = 0; i < n; i++)
        cout << (d[i] == INT_MAX ? "INF" : to_string(d[i])) << endl;
    
    return 0;
}
