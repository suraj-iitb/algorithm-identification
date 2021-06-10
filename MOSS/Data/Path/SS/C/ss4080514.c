#include <bits/stdc++.h>
#define MODNum 1000000007
#define WHITE  0
#define GRAY   1
#define BLACK  2
#define INFTY  2147483647
#define REP(type, i, a, b) for( type i = a; i < b; i++ )
typedef long long ll;

using namespace std;

int main (void) {
    ll N, E, r;
    scanf("%lld %lld %lld", &N, &E, &r);
    int u,v,k;
    //ll c[N][N];    /* 辺の重みを記録した隣接行列 */
    ll d[N];       /* 最短コストの記録 */
    priority_queue<pair<ll,ll>> pq;
    //int p[N];       /* 最短経路木における頂点vの親 */
    int weight;
    vector< vector<pair<ll,ll>> > G(N);

    /* Initialization */
    for ( int i = 0; i < N; i++ ){
        d[i]     = INFTY;
        if ( r == i ){
            pq.push(make_pair(0,i));
            d[i] = 0;
        }
        else{
            pq.push(make_pair(-INFTY,i));
        }
        //p[i]  =  -1;
        //for ( int j = 0; j < N; j++ ) c[i][j] = INFTY;
    }
    /* グラフを読み込み */
    for ( int i = 0; i < E; i++ ){
            scanf("%d %d %d", &u, &v, &weight);
            //c[u][v] = weight;
            G[u].push_back( make_pair(weight, v) );
    }

    while ( !pq.empty() ){
        pair<ll,ll> edgepair  =  pq.top();
        pq.pop();
        u                       =  edgepair.second;
        if ( d[u] < -edgepair.first ) continue;
        //for ( v = 0; v < N; v++ ){
            for ( auto& e:G[u])
          //  if ( c[u][v] != INFTY ){
                if ( d[e.second]    > d[u] + e.first ){
                    d[e.second]     = d[u] + e.first;
                    //p[v]     = u;
                    pq.push(make_pair(-d[e.second],e.second));
                }
            //}
        //}
    }

    for ( int i = 0; i < N; i++ ){
        if ( d[i] != INFTY )
            printf("%d\n", d[i]);
        else printf("INF\n");
    }

    return 0;
}

