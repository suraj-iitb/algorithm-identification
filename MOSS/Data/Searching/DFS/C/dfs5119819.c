#include <stdio.h>
#include <stdlib.h>

#define WHITE 126
#define GRAY 127
#define BLACK 128

int n;

struct Node {
    int id;
    int color;
    int d;
    int f;
    struct Node* pi;
    int* adj;
    int size_adj;
};

struct Node* G;

void input_init(void) {
    scanf("%d", &n);
    G = malloc(sizeof(struct Node)*(n + 1));
    int u, k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &u);
        G[u].id = u;
        scanf("%d", &k);
        G[u].adj = malloc(sizeof(int)*k);
        G[u].size_adj= k;
        for (int j = 0; j < k; j++) {
            scanf("%d", &G[u].adj[j]);
        }
    }
    return;
}

void output(void) {
    for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n", G[i].id, G[i].d, G[i].f);
    }
    return;
}

int time;

void DFS_VISIT(int u) {
    time = time + 1;
    G[u].d = time;
    G[u].color = GRAY;
    for (int i = 0; i < G[u].size_adj; i++) {
        int v = G[u].adj[i];
        if (G[v].color == WHITE) {
            G[v].pi = &G[u];
            DFS_VISIT(v);
        }
    }
    G[u].color = BLACK;
    time = time + 1;
    G[u].f = time;
    return;
}

void DFS(void) {
    for (int u = 1; u <= n; u++) {
        G[u].color = WHITE;
        G[u].pi = NULL;
    }
    time = 0;
    for (int u = 1; u <= n; u++) {
        if (G[u].color == WHITE) {
            DFS_VISIT(u);
        }
    }
    return;
}

int main(void) {
    input_init();
    DFS();
    output();
    return 0;
}

