#include <stdio.h>
#define MAX 101

void dfs(int);

//グローバル変数の初期値は0
int G[MAX][MAX];
int d[MAX], f[MAX];
int n, time = 0;

int main(){
    int u, k, v;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &u, &k);
        for(int j = 0; j < k;j++){
            scanf("%d", &v);
            //頂点uに隣接する点にチェックを入れる
            G[u][v] = 1;
        }
    }

    for(int i = 1; i <= n; i++){
        //まだ一度も発見されてない時だけ
        if(d[i] == 0)dfs(i);
    }

    for(int i = 1; i <= n; i++){
        printf("%d %d %d\n", i, d[i], f[i]);
    }

    return 0;
}

void dfs(int i){
    d[i] = ++time;

    for(int j = 1; j <= n; j++){
        //終了値が0でない時つまり、これ以上進めない時再帰せずに終了できる
        //頂点Gに点が隣接する時かつその点がまだ未発見の時再帰
        if(G[i][j] != 0 && d[j] == 0)dfs(j);
    }

    //終了前に1増える
    time += 1;
    f[i] = time;
}



