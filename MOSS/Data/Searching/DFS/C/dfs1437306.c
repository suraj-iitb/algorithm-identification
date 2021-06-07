#include<stdio.h>
#define MAX 105
#define WHITE 0
#define GRAY 1
#define BLACK 2
void DFS(void);
void DFSVisit(int);
 
int G[MAX][MAX];
int d[MAX];
int f[MAX];
int color[MAX];
int n;
int t;
 

void DFSVisit(int u){
 
    int v;
 
    color[u] = GRAY;
    d[u] = ++t;
    for(v = 1; v <= n; v++){
        if(G[u][v] == 1 && color[v] == WHITE)
            DFSVisit(v);
    }
    color[u] = BLACK;
    f[u] = ++t;
}
void DFS(void){
 
    int u;
 
    for(u = 1; u <= n; u++){
        color[u] = WHITE;
    }
    t = 0;
    for(u = 1; u <= n; u++){
        if(color[u] == WHITE)
            DFSVisit(u);
    }
}
 
int main(){
 
    int i,j,u,k,ne;
 
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            G[i][j] = 0;
        }
    }
    for(i = 1; i <= n;i++){
        scanf("%d",&u);
scanf("%d",&k);
        for(j = 1; j <= k; j++){
            scanf("%d",&ne);
            G[i][ne] = 1;
        }
    }
    DFS();
    for(i = 1; i <= n; i++){
        printf("%d %d %d\n",i,d[i],f[i]);
    }
 
    return 0;
}
 
