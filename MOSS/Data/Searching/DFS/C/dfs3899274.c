#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODE 100

struct Vertex {
    int i;                      /* vertex id */
    int degree;                
    int adj[MAX_NODE + 1];      /* 1 ~ MAX_NODE */
};

static void VertexInitialize(struct Vertex* V, int index) {
    memset(V, 0x00, sizeof(struct Vertex));
    
    V->i = index;
    V->degree = 0;

    return;
}

static void VertexInvalidate(struct Vertex* V) {
    V->i = 0;

    return;
}

static void VertexAddEdge(struct Vertex* V, int v) {
    V->adj[v] = 1;
    V->degree++;

    return;
}

struct Graph {
    int num;
    struct Vertex vertex[MAX_NODE + 1]; /* 1 ~ MAX_NODE */
};

static void GraphInitialize(struct Graph* G) {
    int i;

    G->num = 0;
    for ( i = 0; i <= MAX_NODE; i++ ) {
        VertexInvalidate(&G->vertex[i]);
    }

    return;
}

static void GraphAddEdge(struct Graph* G, int v, int w) {
    VertexAddEdge(&G->vertex[v], w);

    return;
}

static void GraphAddVertex(struct Graph* G, struct Vertex* V) {

    memcpy(&G->vertex[V->i], V, sizeof(struct Vertex));
    G->num++;

    GraphAddEdge(G, 0, V->i);

    return;
}

struct DFS {
    int discovered[MAX_NODE + 1];
    int finished[MAX_NODE + 1];
};

static void DFSInitialize(struct DFS *dfs) {
    memset(dfs, 0x00, sizeof(struct DFS));

    return;
}

static int DFSProcess(struct DFS* dfs, const struct Graph* G, int v, int time) {
    int i;

    dfs->discovered[v] = time++;

    for ( i = 1; i <= G->num; i++ ) {
        if ( G->vertex[v].adj[i] && !dfs->discovered[i] ) {
            time = DFSProcess(dfs, G, i, time);
        }
    }

    dfs->finished[v] = time++;
    
    return time;
}

static void DFS(struct DFS* dfs, const struct Graph* G, int s) {
    int time = 0;
    
    DFSInitialize(dfs);

    time = DFSProcess(dfs, G, s, time);

    return;
}

static void DFSResult(const struct DFS* dfs, const struct Graph* G) {
    int i;

    for ( i = 1; i <= G->num; i++ ) {
        printf("%d %d %d\n", i, dfs->discovered[i], dfs->finished[i]);
    }

    return;
}


int main(int argc, char* argv[]) {
    struct Graph G;
    struct DFS dfs;
    int n;
    int i, j;

    GraphInitialize(&G);

    scanf("%d\n", &n);
    for ( i = 0; i < n; i++ ) {
        struct Vertex V;
        int u, k;
        
        scanf("%d %d", &u, &k);

        VertexInitialize(&V, u);
        GraphAddVertex(&G, &V);
    
        for ( j = 0; j < k; j++ ) {
            int v;
            scanf("%d", &v);

            GraphAddEdge(&G, u, v);
        }
        fgetc(stdin);           /* newline */
    }

    DFS(&dfs, &G, 0);

    DFSResult(&dfs, &G);
        
    return 0;
}


