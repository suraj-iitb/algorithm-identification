#include <bits/stdc++.h>

#define int             long long
#define FOR( i, m, n )  for( int (i) = (m); (i) < (n); (i)++ )
#define REP( i, n )     FOR( i, 0, n )
#define REPR( i, m )    for( int (i) = (m); (i) >= 0; (i)-- )
#define REPONE( i, n )  FOR( i, 1, n + 1 )
#define ALL( a )        (a).begin(), (a).end()
#define MP              make_pair

using namespace std;
using P = pair<int, int>;
using PP = pair<int, pair<int, int> >;

template<class T>bool chmax( T& a, const T& b ) { if( a < b ) { a = b; return 1; } return 0; }
template<class T>bool chmin( T& a, const T& b ) { if( a > b ) { a = b; return 1; } return 0; }

const int INF = 1e9;
const int INFLL = 1e18;
const int MOD = 1e9 + 7;

const int MAX_V = 1e5 + 10;

struct Edge{
    int to, cost;
};

vector<Edge> G[MAX_V];
int d[MAX_V];

signed main(){
    int V, E, r; cin >> V >> E >> r;
    REP( i, E ){
        int from, to, cost; cin >> from >> to >> cost;
        G[from].emplace_back( Edge{ to, cost } );
    }

    fill( d, d + MAX_V, INF );
    d[r] = 0;

    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace( 0, r );
    while( !que.empty() ){
        P p = que.top(); que.pop();
        int v = p.second;
        if( p.first > d[v] ) continue;
        for( auto nv : G[v] ){
            if( chmin( d[nv.to], d[v] + nv.cost ) ){
                que.emplace( d[nv.to], nv.to );
            }
        }
    }

    REP( i, V ){
        if( d[i] != INF ) cout << d[i] << endl;
        else cout << "INF" << endl;
    }
}

