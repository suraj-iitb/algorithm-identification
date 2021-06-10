#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using pll = pair<ll,ll>;
const ll INF64 = 1LL<<60;
const int INF = (1 << 29);

template<typename T>
using Matrix = vector<vector< T >>;
template<typename T>
void warshall_floyd(Matrix< T > &g, T INF){
    for(int k = 0; k < g.size(); k++) {
        for(int i = 0; i < g.size(); i++) {
            for(int j = 0; j < g.size(); j++) {
                if(g[i][k] == INF || g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main(){
    int V,E;
    cin >> V >> E;
    Matrix<int> mat(V, vector<int>(V, INT_MAX));
    rep(i,V) mat[i][i] = 0;
    rep(i,E){
        int s,t,d; cin >> s >> t >> d;
        mat[s][t] = d;
    }
    warshall_floyd(mat, INT_MAX);
    rep(i,V){
        if(mat[i][i]<0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    rep(i,V){
        rep(j,V){
            if(j>0) cout << " ";
            if(mat[i][j]!=INT_MAX) cout << mat[i][j];
            else cout << "INF";
        }
        cout << endl;
    }
}
