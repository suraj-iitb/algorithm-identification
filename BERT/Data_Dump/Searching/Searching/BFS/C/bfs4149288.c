#include<stdio.h>
#define MAX 1000
#define INF 1000000000

void bfs(int id, int dis);

int n;
int G[MAX][MAX], d[MAX];
int size[MAX];//それぞれの頂点から出ている辺の本数を記録しておく配列

int main(){
    int i, j;
    int u, k, v;

    scanf("%d", &n);
    for(i = 1 ; i <= n ; i++){
        d[i] = INF;//距離を「無限の値」に初期化する
        scanf("%d%d", &u, &k);
        size[u] = k;
        for(j = 1 ; j <= size[u] ; j++){
            scanf("%d", &v);
            G[u][j] = v;
        }
    }

    bfs(1, 0);

    for(i = 1 ; i <= n ; i++){
        printf("%d %d\n", i, (d[i] == INF) ? -1 : d[i]);
    }

    return 0;
}

void bfs(int id, int dis){
    int i;

    d[id] = dis;

    for(i = 1 ; i <= size[id] ; i++){
        if(dis + 1 < d[G[id][i]]) bfs(G[id][i], dis + 1);
    }
}

