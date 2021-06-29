#include <stdio.h>
 
#define N 101
 
int M[N][N] = {};
int d[N],f[N];
int t,n;
char c[N];
 
void visit(int v) {
    int i;
 
    c[v] = 'G';
    d[v] = ++t;
    for (i=1;i<=n;i++) {
        if (M[v][i] == 1 && c[i] == 'W') {
            visit(i);
        }
    }
    c[v] = 'B';
    f[v] = ++t;
}
 
void dfs() {
    int i;
    for (i=1;i<=n;i++) c[i] = 'W';
    t = 0;
    for (i=1;i<=n;i++) if (c[i] == 'W') visit(i);
}
 
int main() {
    int i,j;
    int u,k,v;
 
    scanf("%d", &n);
    for (i=1;i<=n;i++) {
        scanf("%d%d",&u,&k);
        for (j=1;j<=k;j++) {
            scanf("%d",&v);
            M[u][v] = 1;
        }
    }
 
    dfs();
 
    for (i=1;i<=n;i++) {
        printf("%d %d %d\n",i,d[i],f[i]);
    }
 
    return 0;
}
