#include<stdio.h>
#define N 101

void dfs();
void visit(int);

int n,G[N][N],DFS[N],time,d[N],f[N];

int main(){
    int u,k,v,i,j;
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d %d",&u,&k);
        for( j = 0 ; j < k ; j++ ){
            scanf("%d",&v);
            G[u][v] = 1;
        }
    }
    dfs();
    return 0;
}

void dfs(){
    int i;
    for( i = 1 ; i <= n ; i++ ) DFS[i] = 0;
    time = 0;
    for( i = 1 ; i <= n ; i++ ){
        if( DFS[i] == 0 ) visit(i);
    }
    for( i = 1 ; i <= n ; i++ ){
        printf("%d %d %d\n",i,d[i],f[i]);
    }
}

void visit(int u){
    int i;
    DFS[u] = 1;
    d[u] = ++time;
    for( i = 1 ; i <= n ; i++ ){
        if( G[u][i] != 1 ) continue;
        if( DFS[i] == 0 ) visit(i);
    }
    DFS[u] == 2;
    f[u] = ++time;
}
