#include <bits/stdc++.h>
using namespace std;
#ifdef TEST_BUILD
#include "my_algorithm.hpp"
#endif
typedef long long ll;


/*
隣接行列を参照渡しするといい感じに計算します。Nodeは0始まり
*/
template<typename Cost>
void warshall_floyd(vector<vector<ll>> &d){
    int V = d.size();
    const Cost INF = numeric_limits<Cost>::max();

    for (int k=0;k<V;k++){
        for (int i=0;i<V;i++){
            for (int j=0;j<V;j++){
                if (d[i][k] != INF && d[k][j] != INF && d[i][k]+d[k][j]<d[i][j]){
                    d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }
}


#ifndef MY_ALGORITHM
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp
int main(){
        int V,E;
        cin >> V >> E;
        const ll INF = numeric_limits<ll>::max();
        vector<vector<ll>> graph(V,vector<ll>(V,INF));
        for (int k=0;k<E;k++){
            ll i,j,c;
            cin >> i >> j >> c;
            graph[i][j] = c;
        }
        for (int k=0;k<V;k++){
            graph[k][k]=0;
        }
        warshall_floyd<ll>(graph);
        for (ll i=0;i<V;i++){
            if (graph[i][i] < 0) {
                printf("NEGATIVE CYCLE\n");
                return 0;
            }
        }
        for (ll i=0;i<V;i++){
            for (ll j=0;j<V;j++){
                if (graph[i][j] == INF){
                    printf("INF");
                }else{
                    printf("%lld",graph[i][j]);
                }

                if (j<V-1){
                    printf(" ");
                }
            }
            printf("\n");
        }
       
}
#endif
