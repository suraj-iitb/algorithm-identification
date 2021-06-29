#include <stdio.h>
#define BLACK 0
#define WHITE 1
#define GRAY -1


int a[101][101];
int f[101];
int n;
int color[101];
int time=0;
int d[101];
int k;

void DFS (void);
void DFSVisit(int);

int main(void){
    int t,u,i,j;

    //printf("point 1\n");
    
    
    scanf("%d",&n);
    
    //printf("point 2\n");
    
    for(i=1;j<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]=0;
        }
    }
    
    for(i=1;i<=n;i++){
       // printf("point 3\n");
        scanf("%d",&u);
       // printf("point 4\n");
        scanf("%d",&k);
       // printf("point 5\n");
            for(j=1;j<=k;j++){
              //  printf("point 6\n");
                scanf("%d",&t);
            // printf("%d %d\n",i,j);
            a[i][t] =1;
        }
    }
    

    
    
    
    
    
    
    
    
    
    
    DFS();
    for(i=1;i<=n;i++){
        printf("%d %d %d\n",i,d[i],f[i]);
    }
    return 0;
}

void DFS(void){
    //int time;
    int u;
    
    for(u=1;u<=n;u++){
        color[u]=WHITE;
        time=0;
    }
    
    for(u=1;u<=n;u++){
        if(color[u]==WHITE)DFSVisit(u);
    }
    
}


void DFSVisit(int u){
    int v;
    
    color[u]=GRAY;
    d[u] = ++time;
    
    for(v=1;v<=n;v++){
        if((color[v]==WHITE) && (a[u][v]==1)){
           DFSVisit(v);
        }
    }
    color[u] = BLACK;
    f[u]=++time;
}
