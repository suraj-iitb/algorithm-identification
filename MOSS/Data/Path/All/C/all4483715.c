#include <bits/stdc++.h>
using namespace std;


template<typename T>
struct WarshallFloyd {
    vector<vector<T>> d;
    WarshallFloyd() = default;
    WarshallFloyd(int n) : d(n, vector<T>(n, numeric_limits<T>::max())){
        for(int i = 0;i < n;++i) d[i][i] = 0;
    }
    void addEdge(int u, int v, T c){
        d[u][v] = c;
    }
    void build(){
        int n = d.size();
        for(int k = 0;k < n;++k) for(int i = 0;i < n;++i) for(int j = 0;j < n;++j)
            if(d[i][k] != numeric_limits<T>::max() and d[k][j] != numeric_limits<T>::max()) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    }
    const vector<T>& operator[](int n) const { return d[n]; }
    bool negativeCycle(){
        int n = d.size();
        for(int i = 0;i < n;++i) if(d[i][i] < 0) return true;
        return false;
    }
};


int V, E;
WarshallFloyd<int> G;


signed main(){
    cin >> V >> E;
    G = WarshallFloyd<int>(V);
    for(int i = 0;i < E;++i){
        int s, t, d;
        cin >> s >> t >> d;
        G.addEdge(s, t, d);
    }

    G.build();

    if(G.negativeCycle()) cout << "NEGATIVE CYCLE" << endl;
    else {
        for(int i = 0;i < V;++i){
            for(int j = 0;j < V;++j){
                if(G[i][j] != numeric_limits<int>::max()) cout << G[i][j];
                else cout << "INF";
                if(j != V-1) cout << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
