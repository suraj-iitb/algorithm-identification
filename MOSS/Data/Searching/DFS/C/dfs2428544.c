#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
void visit(int);
int time = 0;
int d[200],f[200];
int n, u[100], k[100], v[100][100];
int color[100];
int main(void){
int n, i, j;

scanf("%d",&n);
for(i=0;i<n;i++){
    scanf("%d",&u[i]);
    color[u[i]] = WHITE;
    scanf("%d",&k[u[i]]);
    for(j = 0;j< k[u[i]]; j++ ){
        scanf("%d",&v[u[i]][j]);
    }
}
for(i = 1;i<=n;i++){
    if(color[i] == WHITE){
        visit(i);
    }
}
for(i = 1; i<=n; i++){
    printf("%d %d %d\n",i,d[i],f[i] );
}
return 0;
}

void visit(int u){
    int i = 0; 
    color[u] = GRAY;
    d[u] = ++time;
    for(i = 0;i < k[u]; i++){
        if(color[v[u][i]] == WHITE){
        visit(v[u][i]);    
        }
    }
    color[u] = BLACK;
    f[u] = ++time;
}
