#include <stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,BY[MAX][MAX];
int color[MAX],discover[MAX],finish[MAX],time;

void dfs_visit(int);
void dfs();

int main(){
    int i,j,u,k,v;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) BY[i][j]=0;
    }
    for(i=0;i<n;i++){
        scanf("%d%d",&u,&k);
        u--;
        for(j=0;j<k;j++){
            scanf("%d",&v);
            v--;
            BY[u][v]=1;
        }
    }
    dfs();

    return 0;
}

void dfs_visit(int u){
    int i;
    color[u]=GRAY;
    discover[u]=++time;
    for(i=0;i<n;i++){
        if(BY[u][i]==0) continue;
        if(color[i]==WHITE) dfs_visit(i);
    }
    color[u]=BLACK;
    finish[u]=++time;
}
void dfs(){
    int i;
    for(i=0;i<n;i++) color[i]=WHITE;
    time=0;

    for(i=0;i<n;i++){
        if(color[i]==WHITE) dfs_visit(i);
    }
    for(i=0;i<n;i++){
        printf("%d %d %d\n",i+1,discover[i],finish[i]);
    }
}

