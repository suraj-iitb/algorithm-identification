#include <stdio.h>
#include <string.h>
#define N 101
#define M 100

int a[N][N], b[N];

int main() {
    int n, u, k;
    
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &u, &k);
        for(int j = 0; j < k; ++j){
            scanf("%d", &a[u][j]);
        }}
    nom();
    for(int i = 1; i <= n; ++i){
        printf("%d %d\n", i, --b[i]);
    }

    return 0;
}

void nom(){
    int Q[M], id = 0, d = 1;
    
    Q[0] = 1; id++;
    while(id > 0){
        int temp[M], m = 0;
        for (int i = 0; i < id; ++i){
            int u = Q[i];
            if (0 < b[u] && b[u] <= d)
                continue;
            b[u] = d;
            for (int j = 0, v; (v = a[u][j]) > 0; j++){
                temp[m++] = v;
            }}
        memcpy(Q, temp, sizeof(int) * m);
        id = m;
        d++;
    }}
