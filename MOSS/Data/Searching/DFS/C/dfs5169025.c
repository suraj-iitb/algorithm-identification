#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,A[100][100];
int color[100],d[100],f[100],tt;
void dfs(void);
void dfs_visit(int);

int main(){

    int i,j;
    int u,k,v;

    scanf("%d",&n);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++) A[i][j] = 0;
    }
    
    for(i=0; i<n; i++){
        scanf("%d %d ",&u,&k);
        u--;
        for(j=0; j<k; j++){
            scanf("%d",&v);
            v--;
            A[u][v] = 1;
        }
    }

    dfs();

    return 0;
}

void dfs(){
    int i;
    //初期化
    for(i=0; i<n; i++) color[i] = WHITE;
    tt = 0;

    for(i=0; i<n; i++){
        //未訪問のiを始点として深さ優先探索
        if(color[i] == WHITE) dfs_visit(i);
    }

    for(i=0; i<n; i++){
        printf("%d %d %d\n",i+1,d[i],f[i]);
    }

}

//再起関数による深さ優先探索
void dfs_visit(int i){
    int j;
    color[i] = GRAY;
    d[i] = ++tt; //最初の訪問
    for(j=0; j<n; j++){
        if(A[i][j] == 0) continue;
        if(color[j] == WHITE) dfs_visit(j);
    }
    color[i] = BLACK;
    f[i] = ++tt; //訪問終了
}
