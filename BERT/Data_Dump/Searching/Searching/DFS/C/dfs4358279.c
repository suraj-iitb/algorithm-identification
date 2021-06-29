#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **graph;
int n;

int *d;
int *f;
int time;

void _dfs(int idx) {
    d[idx] = ++time;

    for(int j = 0; j < n; j++) {
        if(graph[idx][j] && d[j] == 0) {
            _dfs(j);
        }
    }

    f[idx] = ++time;
}

void dfs() {
    for(int i = 0; i < n; i++) {
        if(f[i] == 0) {
            _dfs(i);
        }
    }
}

int main(void) {

    scanf("%d", &n);
    graph = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        graph[i] = malloc(n * sizeof(int));
        memset(graph[i], 0, n * sizeof(int));
    }
    d = malloc(n * sizeof(int));
    memset(d, 0, n * sizeof(int));
    f = malloc(n * sizeof(int));
    memset(f, 0, n * sizeof(int));

    for(int i = 0; i < n; i++) {
        int uIdx;
        int deg;
        scanf("%d %d", &uIdx, &deg);
        for(int j = 0; j < deg; j++) {
            int vIdx;
            scanf("%d", &vIdx);
            graph[uIdx - 1][vIdx - 1] = 1;
        }
    }

    dfs();
    
    for(int i = 0; i < n; i++) {
        printf("%d %d %d\n", i + 1, d[i], f[i]);
    }

    for(int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
