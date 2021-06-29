#include<stdio.h>
#define N 100       
#define WHITE 0     //未訪問の頂点
#define GRAY 1      //現在訪問中の頂点
#define BLACK 2     //訪問した頂点

int n, M[N][N];     //n：頂点数
int color[N],d[N],f[N],tt;  //d：発見時刻、f：完了時刻、tt：時間

//再起関数による深さ優先探索

void dfs_visit(int u){

    int v;
    color[u] = GRAY;//現在の頂点を訪問中にする。
    d[u] = ++tt;    //発見時刻を記録
    for(v=0;v<n;v++){
        if(M[u][v] == 0) continue;
        if(color[v] == WHITE){  //未訪問の頂点があれば訪問しに行く。
            dfs_visit(v);
        }
    }
    color[u] = BLACK;   //無ければ訪問完了
    f[u] = ++tt;       //完了時刻を記録
}
void dfs(){
    int u;

    //初期化
    for(u=0;u<n;u++) color[u] = WHITE;
    tt = 0;

    for(u=0;u<n;u++){
        //未訪問のuを始点として深さ優先探索
        if(color[u] == WHITE) dfs_visit(u);
    }
    for(u=0;u<n;u++){
        printf("%d %d %d\n", u+1, d[u], f[u]);
    }
}

int main(){
    int u,v,k,i,j;

    scanf("%d",&n);     //要素数
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)M[i][j] = 0;    //配列初期化
    }

    for(i=0;i<n;i++){
        scanf("%d%d",&u,&k);
        u--;

        for(j=0;j<k;j++){
            scanf("%d",&v);
            v--;
            M[u][v] = 1;
        }
    }

    dfs();

    return 0;
}
