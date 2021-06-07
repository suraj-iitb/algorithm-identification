#include<stdio.h>
#include<stdlib.h>
int **matrix, *visit, *queue;
void bfs(int, int);
main()
{
        int i, j, n, u, k, v;
        scanf("%d", &n);
        matrix = (int**)malloc(sizeof(int*) * n);
        visit = (int*)malloc(sizeof(int) * n);
    queue = (int*)malloc(sizeof(int) * n);
        for (i = 0; i < n; i++) {
                matrix[i] = (int*)malloc(sizeof(int) * n);
                visit[i] = 0;
                for (j = 0; j < n; j++) {
                        matrix[i][j] = 0;
                }
                scanf("%d%d", &u, &k);
                for (j = 0; j < k; j++) {
                        scanf("%d", &v);
                        matrix[u - 1][v - 1] = 1;
                }
        }
        bfs(1, n);
        for (i = 0; i < n; i++) {
                printf("%d %d\n", i + 1, visit[i] - 1);
                free(matrix[i]);
        }
        free(matrix);
        free(visit);
        free(queue);
}
void bfs(int p, int size)
{
        int i, pos, head = 0, tail = 0;
        queue[tail++] = p;
        visit[p - 1] = 1;
        do {
                pos = queue[head++];
                for (i = 0; i < size; i++) {
                        if (matrix[pos - 1][i] && !visit[i]) {
                                visit[i] = visit[pos - 1] + 1;
                                queue[tail++] = i + 1;
                        }
                }
        } while (head != tail);
}
