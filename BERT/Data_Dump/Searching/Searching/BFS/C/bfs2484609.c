#include <stdio.h>

#define N 1001
#define INF 1000
#define BLACK 1
#define WHITE 0
int n, color[N][N];
int d[N], t;
int Q[2*N], head=0, back=0;

void enqueue(int x){
    Q[back++] = x;
}
int dequeue(){
    int x;
    x = Q[head++];
    return x;
}
void dfs(int s){
    int i, u, v;
    enqueue(s);
    for(i = 1; i <= n; i++) d[i] = INF;
    d[s] = 0;
    while(head != back){
        u = dequeue();
        for(v = 1; v <= n; v++){
            if(color[u][v] == 0) continue;
            if(d[v] != INF) continue;
            d[v] = d[u] + 1;
            enqueue(v);
        }
    }
}

int main(){
    int u, k, v, i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            color[i][j] = WHITE;
        }
    }
    for(i = 0; i < n; i++){
        scanf("%d %d",&u, &k);
        for(j = 0; j < k; j++){
            scanf("%d",&v);
            color[u][v] = BLACK;
        }
    }
    dfs(1);
    for(i = 1; i <= n; i++){
        if(d[i] == INF) d[i] = -1;
        printf("%d %d\n",i, d[i]);
    }
    return 0;
}
