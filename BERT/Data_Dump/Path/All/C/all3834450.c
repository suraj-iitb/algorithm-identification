#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> P3;
typedef pair<P, P> PP;
constexpr ll MOD = ll(1e9 + 7);
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e5) + 5;
constexpr double EPS = 1e-9;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i > 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

int main() {
    ll V, E, G[105][105];
    cin >> V >> E;
    for(int i=0;i<V;i++){
        fill(G[i], G[i]+V, LLINF/3);
    }
    for(int i=0;i<V;i++){
        G[i][i] = 0;
    }
    for(int i=0;i<E;i++){
        ll u, v, d;
        cin >> u >> v >> d;
        G[u][v] = d;
    }
    bool neg = false;
    for(int t=0;t<10;t++){
        for(int k=0;k<V;k++){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    if(G[i][k] == LLINF/3 || G[k][j] == LLINF/3) continue;
                    if(t>0 && G[i][j] > G[i][k]+G[k][j]){
                        neg = true;
                    }
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        if(G[i][i] < 0) neg = true;
    }
    if(neg){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(G[i][j] < LLINF/3){
                    cout << G[i][j];
                }
                else{
                    cout << "INF";
                }
                cout << " \n"[j==V-1];
            }
        }
    }
    return 0;
}

