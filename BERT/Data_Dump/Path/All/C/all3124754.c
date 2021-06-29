#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const ll inf = 100100100100100;

vector<vector<ll>> warshall_floyd(vector<vector<ll>> edges,int v){
    vector<vector<ll>> ret = edges;
    rep(k,0,v){
        rep(i,0,v){
            rep(j,0,v){
                if(ret[i][k] == inf || ret[k][j] == inf) continue;
                ret[i][j] = min(ret[i][j],ret[i][k] + ret[k][j]);
            }
        }
    }
    return ret;

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    vector<vector<ll>> edges;
    int v,e;
    cin >> v >> e;
    vector<ll> t;
    rep(i,0,v) t.push_back(inf);
    rep(i,0,v) edges.push_back(t);
    rep(i,0,v) edges[i][i] = 0;
    rep(i,0,e){
        int from, to, cost;
        cin >> from >> to >> cost;
        edges[from][to] = cost;
    }

    edges = warshall_floyd(edges,v);

    rep(i,0,v) if(edges[i][i] < 0) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    rep(i,0,v){
        rep(j,0,v){
            if(edges[i][j] < inf) cout << edges[i][j]; else cout << "INF";
            if (j < v-1) cout << " ";
        }
        cout << endl;
    }

    
}
