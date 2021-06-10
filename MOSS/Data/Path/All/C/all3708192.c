#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
long long dist[100][100];

int main(){

    // 1. 入力情報.
    int V, E;
    scanf("%d %d", &V, &E);
    
    // 2. 初期化.
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(i == j) dist[i][i] = 0;
            else       dist[i][j] = INF;
        }
    }
    for(int i = 0; i < E; i++){
        int s, t;
        long long d;
        scanf("%d %d %lld", &s, &t, &d);
        dist[s][t] = d;
    }
    
    // 3. Warshall–Floyd法.
    // https://ja.wikipedia.org/wiki/ワーシャル–フロイド法
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    // 4. 負の閉路持つかを判定.
    bool negative = false;
    for(int i = 0; i < V; i++) if(dist[i][i] < 0) negative = true;
    
    // 5. 出力 ～ 後処理.
    if(negative){
        printf("%s\n", "NEGATIVE CYCLE");
        return 0;
    }else{
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(dist[i][j] > 2e9) printf("%s", "INF");
                else                 printf("%lld", dist[i][j]);
                if(j < V - 1)        printf(" ");
            }
            printf("\n");
        }
    }
    
    return 0;

}
