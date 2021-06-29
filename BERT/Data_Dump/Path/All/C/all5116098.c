#include <iostream>
#include <vector>
#include <tuple>
#define dbg(x) cout << #x << ": " << x << endl;
#define rep(i, a, b) for (int i = a; i < b; i++)

using namespace std;

const long long INF = 1e12 + 7;

long long v, e, s, t, d;
long long dist[100][100];
int main() {
    cin >> v >> e;
    rep(i, 0, v) rep(j, 0, v){
        if(i == j) dist[i][j] = 0;
        else dist[i][j] = INF;
    }
    rep(i, 0, e){
        cin >> s >> t >> d;
        dist[s][t]=d;
    }
    rep(i, 0, v){
        rep(j, 0, v){
            rep(k, 0, v){
                dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
            }
        }
    }
    rep(i, 0, v){
        if(dist[i][i]<0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    rep(i, 0, v){
        rep(j, 0, v-1){
            if(dist[i][j] < 10000000000) cout << dist[i][j] << " ";
            else cout << "INF" << " ";
        }
        if(dist[i][v-1] < 10000000000) cout << dist[i][v-1] << endl;
        else cout << "INF" << endl;
    }
}
