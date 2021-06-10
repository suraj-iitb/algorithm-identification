#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long long LL;
const LL INF = 999999999999;

void Warshall_floyd(vector<vector<LL>> &G){
    int V = G.size();
    rep(k, V)rep(i, V)rep(j, V){
        if(G[i][k] == INF || G[k][j] == INF) continue;
        G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
    }
    // G[i][i] < 0が存在 <=> 負閉路が存在
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<LL>> G(n, vector<LL>(n, INF));
    rep(i, n) G[i][i] = 0;
    rep(i, m){
        int s,t,d;
        cin >> s >> t >> d;
        G[s][t] = d;
    }
    Warshall_floyd(G);
    rep(i, n){
        if(G[i][i] < 0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    rep(i, n){
        rep(j, n){
            if(G[i][j] == INF) cout << "INF";
            else cout << G[i][j];
            cout << (j==n-1 ? "\n":" ");
        }
    }

}



