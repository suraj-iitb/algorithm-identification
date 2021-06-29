#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define MAXE 500000
#define MAXV 100000
#define INF 1010001000
typedef struct edge {
    int from, to;
    int cost;
}edge;
int main()
{
    int i, j, r, sp = 0;
    int V, E;
    int* point;
    edge* root;
    scanf("%d%d%d", &V, &E, &r);
    root = (edge*)malloc(sizeof(edge) * MAXE);
    point = (int*)malloc(sizeof(int) * MAXV);
    for (i = 0; i < V; i++) {
        point[i] = INF;
    }
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &root[i].from, &root[i].to, &root[i].cost);
    }
    point[r] = 0;
    while (sp == 0) {
        sp = 1;
        for (i = 0; i < E; i++) {
            if (point[root[i].from] != INF &&
                point[root[i].to] > point[root[i].from] + root[i].cost) {
                point[root[i].to] = point[root[i].from] + root[i].cost;
                sp = 0;
            }
        }
    }
    for (i = 0; i < V; i++) {
        if (point[i] == INF) {
            printf("INF\n");
        }
        else {
            printf("%d\n", point[i]);
        }
    }
    free(root);
    free(point);
    return 0;
}
