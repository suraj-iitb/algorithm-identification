#include <stdio.h>

#define N 101
#define INF (100000001)

void enqueue(int);
int dequeue();
int isEmpty();
int isFull();

void bfs(int);

int head = 0;
int tail = 0;
int p[N];
int n, M[N][N], d[N];

int main() {
    int i, j;
    int u, k, v;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        scanf("%d %d", &u, &k);
        u--;
        for (j = 0; j < k; j++) {
            scanf("%d", &v);
            v--;
            M[u][v] = 1;
        }
    }
    bfs(0);
    return 0;
}

void bfs(int s) {
    int i, j;
    int u;

    head = 0;
    tail = 0;

    enqueue(s);
    for (i = 0; i < n; i++) {
        d[i] = INF;
    }
    d[s] = 0;

    while (!isEmpty()) {
        u = dequeue();
        for (j = 0; j < n; j++) {
            if (M[u][j] == 0) continue;
            if (d[j] != INF) continue;
            d[j] = d[u] + 1;
            enqueue(j);
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d %d\n", i+1, (d[i] == INF) ? (-1) : (d[i]));
    }
}

void enqueue(int key){
    if (isFull()) {
        return;
    }
    if (tail == N) tail = 0;
    p[tail] = key;
    tail++;
}

int dequeue() {
    int key;
    if (isEmpty()) {
        return -1;
    }
    key = p[head];
    if (head + 1 == N) {
        head = 0;
    } else {
        head ++;
    }

    return key;
}

int isEmpty() {
    return head == tail;
}

int isFull() {
    return head == (tail + 1) % N;
}

