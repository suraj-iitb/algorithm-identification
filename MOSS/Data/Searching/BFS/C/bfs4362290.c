#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int *que;
    int front;
    int rear;
    int size;
    int num;
} Que;

bool initQue(Que *q, int size) {
    if((q->que = malloc(size * sizeof(int))) == NULL) {
        return false;
    }

    q->front = q->rear = q->num = 0;
    q->size = size;
    return true;
}

bool isEmptyQue(Que *q) {
    return q->num <= 0;
}

bool isFullQue(Que *q) {
    return q->num >= q->size;
}

int nextPtr(int ptr, int size) {
    return (ptr + 1) % size;
}

bool enQue(Que *q, int p) {
    if(isFullQue(q)) {
        return false;
    }

    q->que[q->rear] = p;
    q->rear = nextPtr(q->rear, q->size);
    q->num++;

    return true;
}

bool deQue(Que *q, int *p) {
    if(isEmptyQue(q)) {
        return false;
    }

    *p = q->que[q->front];
    q->front = nextPtr(q->front, q->size);
    q->num--;

    return true;
}

void terminateQue(Que *q) {
    free(q->que);
    q->front = q->rear = q->num = q->size = 0;
}

int **graph;
int n;
int *d;

bool isVisited(int u) {
    return d[u] != -1;
}

bool isAdjacent(int u, int v) {
    return graph[u][v];
}

void bfs(int bgn) {
    Que que;

    initQue(&que, n);

    enQue(&que, bgn);
    d[bgn] = 0;
    while(!isEmptyQue(&que)) {
        int u;
        deQue(&que, &u);
        for(int i = 0; i < n; i++) {
            if(!isVisited(i) && isAdjacent(u, i)) {
                d[i] = d[u] + 1;
                enQue(&que, i);
            }
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
    memset(d, -1, n * sizeof(int));

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

    bfs(0);

    for(int i = 0; i < n; i++) {
        printf("%d %d\n", i + 1, d[i]);
    }

    for(int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
