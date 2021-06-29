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
//    VertexAddEdge(&G->vertex[w], v);  // 方向ない場合
    
    return;
}

static void GraphAddVertex(struct Graph* G, struct Vertex* V) {

    memcpy(&G->vertex[V->i], V, sizeof(struct Vertex));
    G->num++;

    GraphAddEdge(G, 0, V->i);

    return;
}

struct QueueData {
    struct QueueData* next;
    int  data;
};

struct Queue {
    struct QueueData* head;
    struct QueueData* tail;
    int count;
};

static void QueueInitialize(struct Queue* queue) {
    queue->head = queue->tail = NULL;
    queue->count = 0;

    return;
}
    
static void QueueEnqueue(struct Queue* queue, int d) {
    struct QueueData* data = malloc(sizeof(struct QueueData));
    data->next = NULL;
    data->data = d;
    
    if ( queue->head == NULL ) {
        queue->head = queue->tail = data;
        queue->tail->next = NULL;
        queue->count++;
    } else {
        queue->tail->next = data;
        queue->tail = data;
        queue->tail->next = NULL;
        queue->count++;
    }

    return;
}

static int QueueDequeue(struct Queue* queue) {
    struct QueueData* head = queue->head;
    int ret;

    if ( queue->head == queue->tail ) {
        queue->head = queue->tail = NULL;
    } else {
        queue->head = queue->head->next;
    }

    queue->count--;

    ret = head->data;
    free(head);

    return ret;
}

static int QueueIsEmpty(const struct Queue* queue) {
    return queue->count == 0;
}
    
struct BFS {
    int visited[MAX_NODE + 1];
    int distance[MAX_NODE + 1];
};

static void BFSInitialize(struct BFS *bfs) {
    memset(bfs, 0x00, sizeof(struct BFS));

    for (int i = 0; i <= MAX_NODE + 1; i++ ) {
        bfs->distance[i] = -1;
    }

    return;
}

static void BFS(struct BFS* bfs, const struct Graph* G, int s) {
    struct Queue queue;

    QueueInitialize(&queue);

    QueueEnqueue(&queue, s);

    bfs->visited[s] = 1;
    bfs->distance[s] = 0;

    while ( !QueueIsEmpty(&queue) ) {
        int v = QueueDequeue(&queue);

        for ( int w = 1; w <= G->num; w++ ) {
            if ( G->vertex[v].adj[w] && !bfs->visited[w] ) {
                QueueEnqueue(&queue, w);
                bfs->visited[w] = 1;
                bfs->distance[w] = bfs->distance[v] + 1;
            }
        }
    }

    return;
}

static void BFSPrint(const struct BFS* bfs, const struct Graph* G) {
    int i;

    for ( i = 1; i <= G->num; i++ ) {
        printf("%d %d\n", i, bfs->distance[i]);
    }

    return;
}


int main(int argc, char* argv[]) {
    struct Graph G;
    struct BFS bfs;
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

    BFSInitialize(&bfs);

    BFS(&bfs, &G, 1);

    BFSPrint(&bfs, &G);

    return 0;
}

