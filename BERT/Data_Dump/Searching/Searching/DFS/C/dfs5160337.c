#include<stdio.h>
#include<stdlib.h>//
#define  N 100
#define white 0
#define gray 1
#define black 2


int n;//input number
int A[N][N];
int color[N];
int D[N],F[N];
int t;

void DFS(int u){//最初（○/□）の○の方
    int i;
    color[u] = gray;
    D[u] = ++t;
    for(i=0;i<n;i++){
        if(A[u][i]==0)
            continue;
        if(color[i]==white){
            DFS(i);
        }
    }
    color[u]=black;
    F[u] = ++t;
}
void dfs(int u){
    for(u=0;u<n;u++){//初期化
        color[u]=white;
        t = 0;
    }
    for(u=0;u<n;u++){//uを始点
        if(color[u]==white)
        DFS(u);
    }
    for(u=0;u<n;u++){
        printf("%d %d %d\n",u+1,D[u],F[u]);

    }
}


int main(){
    int u,v,k;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            A[i][j] = 0;
        }
    }
    for(i=0;i<n;i++){
        scanf("%d %d",&u,&k);
        u--;
        for(j=0;j<k;j++){
            scanf("%d",&v);
            v--;
            A[u][v] = 1;

        }

    }

    dfs(u);
    return 0;    
}

