#include<stdio.h>
#define WHITE 1
#define GRAY 2
#define BLACK 3

int array[500][500],d[100],f[100],color[100];
int n,time_;

void dfs(void);
void visit(int);
void print(void);

int main(){
    int u,v,i,j,jisu;

    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            array[i][j] = 0;
        }
    }

    for(i=0;i<n;i++){
        scanf("%d%d",&u,&jisu);
        u = u - 1;
        for(j=0;j<jisu;j++){
            scanf("%d",&v);
            v = v - 1;
            array[u][v] = 1;
        }
    }

    dfs();

    return 0;
}
void dfs(){
    int u;

    for(u=0;u<n;u++){
        color[u] = WHITE;
    }
    time_ = 0;

    for(u=0;u<n;u++){
        if(color[u] == WHITE){
            visit(u);
        }
    }
    print();
}
void visit(int u){
    int v;

    color[u] = GRAY;
    d[u] = ++time_;
    for(v=0;v<n;v++){
        if(array[u][v] == 0){
            continue;
        }
        if(color[v] == WHITE){
            visit(v);
        }
    }
    color[u] = BLACK;
    f[u] = ++time_;
}
void print(){
    int i;

    for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
    }
}
