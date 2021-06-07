#include <stdio.h>
#define BLACK 2
#define WHITE 0
#define GRAY 1
void visit(int, int);
void dfs(int);

int d[101], f[101], stack[101], key = 0, color[101], time;
int a[101][101] = {0};

void dfs(int n){
    int i,j;
    for(i = 1; i <= n; i++){
        color[i] = WHITE;
    }
    time = 0;
    for(i = 1; i <= n; i++){
        if(color[i] == WHITE)visit(i, n);
    }
}

void visit(int u, int n){
    int i;
    color[u] = GRAY;
    d[u] = ++time;
    for(i = 1; i <=n; i++){
        if(a[u][i] == 1){
            if(color[i] == WHITE){
                visit(i, n);
            }
        }
    }
    f[u] = ++time;
}

int main(){
    int n, i, j, k, u, v;
    
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d %d", &u, &k);
        for(j = 1; j <= k; j++){
            scanf("%d", &v);
            a[u][v] = 1;
        }
    }

    dfs(n);

    for(i = 1;i <=n; i++){
        printf("%d %d %d\n", i, d[i], f[i]);
    }
    return 0;
}
