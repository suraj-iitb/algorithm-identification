#include <stdio.h>
#define M 100
#define W 0
#define G 1
#define B 2

int n,A[M][M];
int clr[M],k[M],t[M],s;

void dfs(int u){
    int x;
    clr[u]=G;
    k[u]=++s;
    for(x=0;x<n;x++){
        if(A[u][x] == 0)continue;
        if(clr[x] == W){
            dfs(x);
        }
    }
    clr[u]==B;
    t[u]=++s;
}

void dfs2(){
    int y;

    for(y=0;y<n;y++){
        clr[y]=W;
        s=0;
    }
    for(y=0;y<n;y++){
        if(clr[y] == W)dfs(y);
    }

    for(y=0;y<n;y++){
        printf("%d %d %d\n",y+1,k[y],t[y]);
    }
}

int main(){
    int i,j,x,y,z;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            A[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        x--;
        for(j=0;j<y;j++){
            scanf("%d",&z);
            z--;
            A[x][z]=1;
        }
    }
    dfs2();

    return 0;
}

