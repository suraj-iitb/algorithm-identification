#include <stdio.h>

int graph[101][101], d[101], f[101], n, color[101], timee;

void visit(int u) {
    int i;
    color[u] = 0;
    d[u] = ++timee;
    for (i = 1; i <= n; i++) {
        if (graph[u][i] == 1) {
            if (color[i] == 1) visit(i);
        }
    }
    color[u] = -1;
    f[u] = ++timee;
}

void dfs() {
    int i;
    for (i = 1; i <= n; i++) color[i] = 1;
    timee = 0;
    for (i = 1; i <= n; i++) {
        if (color[i] == 1) visit(i);
    }
}

int main(void){
    int dd, i, a, j, n2;
    scanf("%d", &n);
    
    for (i = 1; i <= 100; i++) {
        for (j = 1; j <= 100; j++) {
            graph[i][j] = 0;
        }
    }
    
    for (i = 0; i < n; i++) {
        scanf("%d %d", &dd, &n2);
        for (j = 0; j < n2; j++) {
            scanf("%d", &a);
            graph[dd][a] = 1;
        }
    }
    
    dfs();
    
    for (i = 1; i <= n; i++) {
        printf("%d %d %d\n", i, d[i], f[i]);
    }
    
    return 0;
}

