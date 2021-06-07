#include<stdio.h>

#define BLACK 2
#define GRAY  1
#define WHITE 0
#define MAX 100

int n=0, time=0;
int color[MAX]={};
int d[MAX]={}, f[MAX]={};
int matrix[MAX][MAX] = {};

void dfs();
void visit(int);

int main(void){
    int i, j;
    scanf("%d\n", &n);

    
    for(i = 0; i < n; i++){
        int u, k, v;
        scanf("%d %d", &u, &k);
        for(j=0;j<k;j++){
            scanf(" %d", &v);
            matrix[u-1][v-1]=1;
        }
    }

    dfs();

    for(i=0;i<n;i++){
        printf("%d %d %d\n", i+1, d[i], f[i]);
    }

    return 0;
}

void dfs(){
    int i;
    for(i=0; i<n; i++){
        if(color[i] == WHITE){
            visit(i);
        }
    }
}

void visit(int u){
    int i, j;
    color[u] = GRAY;
    d[u] = ++time;
    for(i=0;i<n;i++){
        if(matrix[u][i] && color[i] == WHITE){
            visit(i);
        }
    }
    color[u] = BLACK;
    f[u] = ++time;
}
