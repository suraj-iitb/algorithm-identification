#include <stdio.h>
#include <string.h>
#define N 100

int M[N][N];
int distance[N];//距離で訪問状態を管理

void bfs(void) {
    int queue[N], l = 0, d = 1;//標準ライブラリqueue
    queue[0] = 1;
    l++;
    while (l > 0) {
        int temp[N];
        int m = 0;
        
        for (int i = 0 ; i < l ; i++) {
            int u = queue[i];
            if (0 < distance[u] && distance[u] <= d) continue;
            distance[u] = d;
            for (int j = 0, v ; (v = M[u][j]) > 0 ; j++) temp[m++] = v;
        }
        memcpy(queue, temp, sizeof(int)* m);
        l = m;
        d++;
    }
}

int main(void) {
    int u, k, n;
    scanf("%d", &n);
    
    for (int i = 0 ; i < n ; i++) {
        scanf("%d %d", &u, &k);
        for (int j = 0 ; j < k ; j++) {
            scanf("%d", &M[u][j]);
        }
    }
    bfs();
    for (int i = 1 ; i <= n; i++) {
        printf("%d %d\n", i, --distance[i]);
    }

    return 0;
}
