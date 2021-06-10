#include<bits/stdc++.h>
using namespace std;

using ll= long long;
const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

/* warshall_floyd(dist,prev)
    入力：初期化した dist, prev
    計算量：O(|V|^3)
    副作用：dis[i][j]にiからjへの最短路のコストを格納、prev[i][j]にiからjへの最短路でのjの1つ前の点を格納
    負の辺があっても動作する。
*/
struct warshall_floyd{
    int V;
    vector<vector<ll>> dist;
    vector<vector<int>> prev; 
    warshall_floyd(const vector<vector<ll>> cost){init(cost);}
    void init(const vector<vector<ll>> cost){
        V=(int)cost.size();
        dist=cost;
        prev.assign(V, vector<int>(V, -1));
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(cost[i][j] != LINF) prev[i][j]=i;
            }
        }

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        prev[i][j] = prev[k][j];
                    }
                }
            }
        }
    }

    //s -> t path
    vector<int> get_path(int s, int t) {
        vector<int> path;
        for (int cur = t; cur != s; cur = prev[s][cur]) {
            if(cur == -1){
                path.clear();
                path.push_back(-1);
                return path;
            }
            path.push_back(cur);
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        return path;
    }

    //negative_cycle
    bool is_negative() {
        int V = dist.size();
        for (int i = 0; i < V; i++) {
            if (dist[i][i] < 0) {
                return true;
            }
        }
        return false;
    }
};




int main() {
    int V, E; cin >> V >> E;
    vector<vector<ll>> cost(V, vector<ll>(V, LINF));
    for(int i=0; i<V; i++) cost[i][i]=0;
    for(int i=0; i<E; i++){
        int s, t, d; cin >> s >> t >> d;
        cost[s][t]=d;
    }

    warshall_floyd wf(cost);
    if(wf.is_negative()) cout << "NEGATIVE CYCLE" << endl;
    else{
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(wf.dist[i][j] >= LINF/2) cout << "INF";
                else cout << wf.dist[i][j];
                cout << (j==V-1?"\n":" ");
            }
        }
    }

    return 0;
}
