#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000;
vector<long long> dijkstra(vector<vector<pair<int, int>>> &E, int s){
    int V = E.size();
    vector<long long> d(V, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
    Q.push(make_pair(0, s));
    while (!Q.empty()){
        long long c = Q.top().first;
        int v = Q.top().second;
        Q.pop();
        if (d[v] == INF){
            d[v] = c;
            for (int i = 0; i < E[v].size(); i++){
                Q.push(make_pair(c + E[v][i].first, E[v][i].second));
            }
        }
    }
    return d;
}
int main(){
  int V, E, r;
  cin >> V >> E >> r;
  vector<vector<pair<int, int>>> e(V);
  for (int i = 0; i < E; i++){
    int s, t, d;
    cin >> s >> t >> d;
    e[s].push_back(make_pair(d, t));
  }
  vector<long long> d = dijkstra(e, r);
  for (int i = 0; i < V; i++){
    if (d[i] != INF){
      cout << d[i] << endl;
    } else {
      cout << "INF" << endl;
    }
  }
}
