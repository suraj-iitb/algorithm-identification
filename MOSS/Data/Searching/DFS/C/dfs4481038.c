#include <stdio.h>
#include <stdlib.h>

static int current;

void DFS(int *d, int *f, int **edges, int n, int i)
{
    int j;

    //if(d[i] != 0) {
    //    return;
    //}

    //fprintf(stderr, "%d\n", i);

    if(d[i] == 0) {
        d[i] = current;
        current += 1;
    }
    for(j = 0; j < n; j++) {
        if(edges[i][j] != 0 && d[j] == 0) {
            DFS(d, f, edges, n, j);
            if(f[j] == 0) {
                f[j] = current;
                current += 1;
            }
        }
    }
    if(f[i] == 0) {
        f[i] = current;
        current += 1;
    }
}

int main()
{
    int n;
    int u;
    int k;
    int v;
    int *d;
    int *f;
    int i;
    int j;
    int **edges;


    scanf("%d", &n);
    d = (int *)malloc(sizeof(int) * n);
    f = (int *)malloc(sizeof(int) * n);
    edges = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; i++) {
        d[i] = 0;
        f[i] = 0;
        edges[i] = (int *)malloc(sizeof(int) * n);
        for(j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for(i = 0; i < n; i++) {
        scanf("%d %d", &u, &k);
        for(j = 0; j < k; j++) {
            scanf("%d", &v);
            edges[u-1][v-1] = 1;
        }
    }

#if 0
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", edges[i][j]);
        }
        printf("\n");
    }
#endif

    current = 1;
    for(i = 0; i < n; i++) {
        //fprintf(stderr, "[%d] \n", i);
        if(d[i] == 0) {
            DFS(d, f, edges, n, i);
        }
    }

    for(i = 0; i < n; i++) {
        printf("%d %d %d\n", i+1, d[i], f[i]);
    }

    return 0;
}
