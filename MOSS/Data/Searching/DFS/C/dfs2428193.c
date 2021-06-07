#include<stdio.h>
#define N 100
#define DISCOVERY 0
#define FINISHING 1

int n, k, l, t;
int A[N][N];
int B[N][2];
int cnt;

int searchYet() {
    int i;
    for ( i = 0; i < n; i++) {
        if(B[i][DISCOVERY] == 0) return i;
    }
    return -1;
}

void dfs(int v) {
    int i, j;
    B[v][DISCOVERY] = ++cnt;
    for ( i = 0; i < n; i++) {
        if (A[v][i] == 1 && B[i][DISCOVERY] == 0) {
            dfs(i);
        }
    }
    B[v][FINISHING] = ++cnt;
    return;
}

int main() {
    int i, j;
    int res;
    
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            A[i][j] = 0;
        }
    }
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < 2; j++) {
            B[i][j] = 0;
        }
    }

    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d%d",&l , &k);
        for ( j = 0; j < k; j++) {
            scanf("%d", &t);
            A[l-1][t-1] = 1;
        }
    }
    
    dfs(0);
    while(1){
        res = searchYet();
        if (res == -1) break;
        dfs(res);
    }

    for ( i = 0; i < n; i++) {
        printf("%d ", i+1);
        printf("%d %d", B[i][DISCOVERY], B[i][FINISHING]);
        printf("\n");
    }
    
    return 0;
}
