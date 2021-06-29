#include <stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int matrix[MAX+1][MAX+1];
int color[MAX+1];
int d[MAX+1];
int f[MAX+1];
int n;
int time;

void visit(int u){

    int v;

    color[u] = GRAY;
    d[u] = ++time;

    for( v = 1 ; v <= n ; v++ ){

        if( matrix[u][v] == 0 ){
            continue;
        }
        if( color[v] == WHITE ){
            visit(v);
        }
    }

    color[u] = BLACK;
    f[u] = ++time;


}

void dfs(){

    int u;

    for( u = 0 ; u <= n ; u++ ){
        color[u] = WHITE;
    }

    time = 0;

    for( u = 1 ; u <= n ; u++ ){
        if( color[u] == WHITE ){
            visit(u);
        }
    }

    for( u = 1 ; u <= n ; u++ ){
        printf("%d %d %d\n",u,d[u],f[u]);
    }

}



int main(){

    int i,j;
    int row,col;
    int num;

    scanf("%d",&n);

    for( i = 0 ; i <= n ; i++ ){
        for( j = 0 ; j <= n ; j++ ){
            matrix[i][j] = 0;
        }
    }

    for( i = 1 ; i <= n ; i++ ){

        scanf("%d",&row);
        scanf("%d",&col);

        for( j = 0 ; j < col ; j++ ){
            scanf("%d",&num);
            matrix[row][num] = 1;
        }

    }
    

    dfs();

    return 0;

}
