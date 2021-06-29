#include <stdio.h>

#define N 100

int arrayg[N][N], arrayn[N], arraywid[N];

void Defdep(int a, int k){
    int i;

    arraywid[a] = k;

    for (i = 1; i <= arrayn[a]; i++){
        if (arraywid[arrayg[a][i]] > k){
            Defdep(arrayg[a][i], k + 1);
        }
    }
}

int main(void){
    int i,j;
    int n,l;

    scanf("%d", &n);

    for (i = 1; i <= n; i++){
        arraywid[i] = N * N;
        for (j = 1; j <= n; j++){
            arrayg[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++){
        scanf("%d", &l);
        scanf("%d", &arrayn[l]);
        for (j = 1; j <= arrayn[l]; j++){
            scanf("%d", &arrayg[l][j]);
        }
    }

    Defdep(1, 0);

    for (i = 1; i <= n; i++){
        if (arraywid[i] == N * N){
            arraywid[i] = -1;
        }
        printf("%d %d\n", i, arraywid[i]);
    }

    return 0;
}


