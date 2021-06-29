#include<stdio.h>
#include<stdlib.h>
#define  WHITE 0
#define  BLACK 1
#define  GRAY 2
int n,time;

typedef struct graph{
    int u;//vertex;
    int v[100];
    int k;
    int color;
    int f;
    int d;
}Graph;

void visit(Graph G[],int u){
    int i,m;
    G[u].color=GRAY;
    G[u].d=++time;
    for(i=0;i<G[u].k;i++){
        if(G[G[u].v[i]].color==WHITE){
            visit(G,G[G[u].v[i]].u);
        }
    }
    G[u].color=BLACK;
    G[u].f=++time;
}

void dfs(Graph G[]){
    int i;
    for(i=1;i<=n;i++){
        G[i].color=WHITE;
    }
    for(i=1;i<=n;i++){
        if(G[i].color==WHITE){
            visit(G,G[i].u);
        }
    }
}

int main(){
    int i,j;
    Graph G[100];
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&G[i].u,&G[i].k);
        for(j=0;j<G[i].k;j++){
            scanf("%d",&G[i].v[j]);
        }
    }
    dfs(G);
    for(i=1;i<=n;i++){
        printf("%d %d %d\n",G[i].u,G[i].d,G[i].f);
    }
    return 0;
}


