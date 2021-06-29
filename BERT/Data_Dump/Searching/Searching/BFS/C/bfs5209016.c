#include <stdio.h>

#define M 101
#define N 10000

int main(void)
{
    int n, u, k;
    int node[M][M];
    int queue[N][2];
    int d[M];
    int read, write;
    int i, j;
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d%d", &u, &k);
        
        node[u][0] = k;
        for (j = 1; j <= k; j++){
            scanf("%d", &node[u][j]);
        }
    }
    
    for (i = 1; i <= n; i++){
        d[i] = -1;
    }

    read = 0;
    write = 1;
    
    queue[0][0] = 1;
    queue[0][1] = 0;
    
    d[1] = 0;

    while (read < write){
        for (i = 1; i <= node[queue[read][0]][0]; i++){
            queue[write][0] = node[queue[read][0]][i];
            queue[write][1] = queue[read][1] + 1;

            if (d[queue[write][0]] == -1){
                d[queue[write][0]] = queue[write][1];
            }

            write++;
        }
        node[queue[read][0]][0] = 0;
        read++;
        
#if 0
        
#endif
    }
    
    for (i = 1; i <= n; i++){
        printf("%d %d\n", i, d[i]);
    }
    
    return (0);
}

    

