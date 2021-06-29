#include <stdio.h>
#include <stdlib.h>

void visit(int u, int** A, int n, int* color, int* f, int* d, int* ptime) {
    color[u] = 1;
    d[u] = ++(*ptime);
    for (int i = 0; i < n; i++) {
        if (A[u][i] == 1 && color[i] == 0) {
            visit(i, A, n, color, f, d, ptime);
        }
    }
    color[u] = 2;
    f[u] = ++(*ptime);
}


int main() {
    int n;
    scanf("%d", &n);
    int* d = malloc(sizeof(int) * n);
    int* f = malloc(sizeof(int) * n);
    int* color = malloc(sizeof(int) * n);
    int** A = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        A[i] = malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
        color[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int id, ato;
        int size;
        scanf("%d %d", &id, &size);
        for (int j = 0; j < size; j++) {
            scanf("%d", &ato);
            //printf("id %d, size %d, ato %d\n", id, size, ato);
            A[id - 1][ato - 1] = 1;
        }
    }

    int time = 0;

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            visit(i, A, n, color, f, d, &time);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", i+1, d[i], f[i]);
    }

	return 0;
}

