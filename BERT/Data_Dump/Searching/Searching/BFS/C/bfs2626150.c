#include <stdio.h>
#define white 0
#define black 1

int a[100][100], n, t, d[100], q[100], color[100],qq;

void bps(int s) {
    int i;
    for (i = 0; i < n; ++i) {
        if (a[s][i] == 1) {
            if (color[i] == white) {
                color[i] = black;
                q[qq++] = i;
                d[i] = d[s] + 1;
            }
            else {
                if (d[s] + 1 < d[i]) d[i] = d[s] + 1;
            }
        }
    }
    
    if (t < qq){
        bps(q[t++]);
    }
    
}

int main() {
    int i, j, u, k, b;
    scanf("%d", &n);
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            a[i][j]  = 0;
        }
    }
    
    for (i = 0; i < n; ++i) {
        scanf("%d %d", &u, &k);
        for (j = 0; j < k; ++j) {
            scanf("%d", &b);
            a[u-1][b-1]  = 1;
        }
    }
    
    
    for (i = 0; i < n; ++i) {
        color[i] = white;
    }
    qq = 0;
    t = 0;
    color[0]=black;
    d[0] = 0;
    bps(0);
    
    for (i = 1; i < n; ++i) {
        if (color[i] == white) d[i] = -1;
    }
    
    for (i = 0; i < n; ++i) {
        printf("%d %d\n", i+1, d[i]);
    }
    
    return 0;
}
