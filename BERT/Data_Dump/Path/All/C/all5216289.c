#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int V,E; cin >> V >> E;
    vector<vector<ll>> dist(V, vector<ll> (V, 1e18));
    
    rep(i,E){
        int s,t; ll d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    rep(i,V) dist[i][i] = 0;

    rep(k,V)rep(i,V)rep(j,V){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    // if dist[i][i] < 0 then negative_cycle
    rep(i,V) if(dist[i][i] < 0){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    rep(i,V){
        rep(j,V){
            if(j) cout << " ";
            if(dist[i][j] < 1e18 / 2) cout << dist[i][j];
            else cout << "INF";
        }
        cout << '\n';
    }
}
