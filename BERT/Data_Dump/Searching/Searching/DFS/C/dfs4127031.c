#include <stdio.h>
#include <stdlib.h>

#define INF 1000000
#define WHITE 0
#define GLAY 1
#define BLACK 2

int *d, *f, *color;
int n, t;
int mat[128][128];

void dfs(int);
void dfs_init();

int main(){
        int u, k, num;
        int i, j;

        for(i = 1 ; i <= n ; i++){
                for(j = 1 ; j <= n ; j++){
                        mat[i][j] = 0;
                }
        }

        scanf("%d", &n);

        d = malloc((n + 2) * sizeof(int));
        f = malloc((n + 2) * sizeof(int));
        color = malloc((n + 2) * sizeof(int));

        for(i = 1 ; i <= n ; i++){
                scanf("%d %d", &u, &k);
                for(j = 0 ; j < k ; j++){
                        scanf("%d", &num);
                        mat[u][num] = 1;
                }
        }

        dfs_init();

        for(i = 1; i <= n ; i ++){
                printf("%d %d %d\n", i, d[i], f[i]);
        }

        return 0;
}

void dfs(int u){
        int i;
        color[u] = GLAY;
        d[u] = ++t;
        for(i = 1 ; i <= n ; i++){
                if((mat[u][i] == 1) && (color[i] == WHITE))dfs(i);
        }
        color[u] = BLACK;
        f[u] = ++t;
}

void dfs_init(){
        int i;
        for(i = 1 ; i <= n ; i++){
                color[i] = WHITE;
        }
        for(i = 1 ; i <= n ; i++){
                if(color[i] == WHITE)dfs(i);
        }
}

