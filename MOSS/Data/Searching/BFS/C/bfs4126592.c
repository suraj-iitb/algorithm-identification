#include <stdio.h>
#include <stdlib.h>

int graph[101][101], d[101], n, color[101], queue[10000], head, tail;

void enqueue(int key) {
    queue[tail++] = key;
}

int dequeue() {
    return queue[head++];
}

void bfs() {
    int i, u;
    for (i = 2; i <= n; i++) {
        color[i] = 1;
        d[i] = -1;
    }
    color[1] = 0;
    head = 0;
    tail = 0;
    enqueue(1);
    while (head <= tail) {
        u = dequeue();
        for (i = 1; i <= n; i++) {
            if (graph[u][i] == 1) {
                if (color[i] == 1) {
                    color[i] = 0;
                    d[i] = d[u] + 1;
                    enqueue(i);
                }
            }
        }
        color[u] = -1;
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
    
    bfs();
    
    for (i = 1; i <= n; i++) {
        printf("%d %d\n", i, d[i]);
    }
    
    return 0;
}


