#include<stdio.h>

#define B 2
#define G 1
#define W 0

int Q[100];
int head = 0, tail = 0;

void enqueue(int x) {
    Q[tail] = x;
    tail = (tail + 1) % 100;
}

int dequeue() {
    int x;
    x = Q[head];
    head = (head + 1) % 100;
    return x;
}

int main() {
    int i, j;
    int u, k, v,ver;
    int col[101], wei[101],adj[101][101];
    int n;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        col[i] = W;
        wei[i] = -1;
        for (j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }
    
    for (i = 0; i < n; i++) {
        scanf("%d%d", &u, &k);
        for (j = 0; j < k; j++) {
            scanf("%d", &v);
            adj[u][v] = 1;
        }
    }

    col[1] = G;
    wei[1] = 0;

    enqueue(1);
    
    while(head!=tail){
        ver = dequeue();

        for (i = 1; i <= n; i++) {
            if (col[i] == W && adj[ver][i]== 1) {
                col[i] = G;
                wei[i] = wei[ver]+1;
                enqueue(i);
            }
        }

        col[ver] = B;
    }

    for (i = 1; i <= n; i++) printf("%d %d\n", i, wei[i]);
    
    return 0;
}

