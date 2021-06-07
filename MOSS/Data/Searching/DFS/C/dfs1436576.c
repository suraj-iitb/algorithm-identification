#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK -1
typedef struct ver{
    int id;
    int d;
    int f;
}ver;
ver V[110];
int A[110][100], n, d[110], color[110], f[110];
void visit(int u){
    int v=1;
    int static time=0;
    color[u] = GRAY;
    d[u] = ++time;
    while(A[u][v] != 0){ // Explore edge (u,v)
        if(color[A[u][v]] == WHITE)
            visit(A[u][v]);
        v++;
    }
    color[u] = BLACK;
    f[u] = ++time;
}

void dfs(){
    int i;
    for(i = 1; i < n; i++)
        color[i]= WHITE;
    for(i = 1; i < n; i++){
        if(color[i] == 0) visit(i);
    }
}

int main(){
    int i, j, k, u, v;
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++)
            A[i][j] = 0;
    }
    for(i = 1; i <= n; i++){
        scanf("%d",&u);
        V[i].id = u;
        scanf("%d", &k);
        for(j = 1; j <= k; j++){
            scanf("%d",&v);
            A[u][j] = v;
        }
    }
    dfs();
    for(i = 1; i <= n; i++)
        printf("%d %d %d\n",V[i].id, d[i], f[i]);
    return 0;
}
