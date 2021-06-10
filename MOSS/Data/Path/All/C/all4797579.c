#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main (){
    int v, e ;
    cin >> v >> e ;
    vector<vector<ll>> g (v, vector<ll> (v, INF)) ;
    rep(i, v) g[i][i] = 0 ;
    rep(i, e){
        int s, t ;
        ll d ; 
        cin >> s >> t >> d ;
        g[s][t] = d ; 
    }
    rep(k, v){
        rep(i, v){
            rep(j, v){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]) ;
            }
        }
    }
    rep(i, v){
        if(g[i][i] < 0){
            cout << "NEGATIVE CYCLE" << endl ;
            return 0 ;
        }
    }
    rep(i, v){
        rep(j, v){
            if(j == v-1){
                if(g[i][j] > 1e16){
                    cout << "INF" ;
                    continue ;
                }
                else {
                    cout << g[i][j] ;
                    continue ;
                }       
            }
            if(g[i][j] > 1e16){
                cout << "INF" << " " ;
            }
            else {
                cout << g[i][j] << " " ;
            }
        }
        cout << endl ;
    }
}

