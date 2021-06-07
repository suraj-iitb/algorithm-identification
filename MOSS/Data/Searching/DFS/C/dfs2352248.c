#include <stdio.h>
#define REP(i, n) for(i = 0; i < n; i++)
#define N 100
#define NOTVISITED   0
#define NOWSEARCHING 1
#define VISITED      2

int n, M[N][N];
int state[N], d[N], f[N], time;

void dfs(int v) {
    int i;
    d[v] = time;
    time += 1;
    state[v] = NOWSEARCHING;
    REP(i, n) {
        if(M[v][i] == 1 && state[i] == NOTVISITED) {
            dfs(i);
        }
    }
    state[v] = VISITED;
    f[v] = time;
    time += 1;
}


int main(void) {
    int u, k, v;
    int i, j;

    scanf("%d", &n);
    REP(i, n) REP(j, n) M[i][j] = 0;
    REP(i, n) state[i] = NOTVISITED;

    REP(i, n) {
        scanf("%d %d", &u, &k);
        REP(j, k) {
            scanf("%d", &v);
            M[u - 1][v - 1] = 1;
        }
    }

    time = 1;
    REP(v, n) {
        if(state[v] == NOTVISITED) {
            dfs(v);
        }
    }

    REP(i, n) printf("%d %d %d\n", i + 1, d[i], f[i]);

    return 0;
}
