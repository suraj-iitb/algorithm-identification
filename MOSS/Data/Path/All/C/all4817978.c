#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MOD (int)(1e9 + 7) 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v, e; bool neg = false;
    cin >> v >> e;
    vector<vector<ll>> cost(v, vector<ll>(v, INF));
    for(int i = 0; i < e; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;
        cost[x][y] = z;
    }
    for(int i = 0; i < v; ++i) cost[i][i] = 0;
    for(int k = 0; k < v; ++k) {
        for(int i = 0; i < v; ++i) {
            for(int j = 0; j < v; ++j) {
                if(cost[i][k] != INF and cost[k][j] != INF and cost[i][k] + cost[k][j] < cost[i][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
            if(cost[i][i] < 0) {
                neg = true;
                break;
            }
        }
    }
    if(!neg) {
        for(int i = 0; i < v; ++i) {
            for(int j = 0; j < v; ++j) {
                if(cost[i][j] != INF) cout << cost[i][j];
                else cout << "INF";
                if(j == v-1) cout << '\n';
                else cout << ' ';
            }
        }
    }
    else {
        cout << "NEGATIVE CYCLE\n";
    }
    return 0;
}
