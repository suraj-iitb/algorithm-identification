#include<stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int map[N][N] = {0}, color[N], d[N], f[N];
int time = 0, n;

void dfs();
void visit(int);

int main()
{
    int i, j, u, k, v;

    scanf("%d", &n);
    for(i = 0 ; i < n ; i++) {
       scanf("%d%d", &u, &k);
       for(j = 0 ; j < k ; j++) {
           scanf("%d", &v);
           map[u - 1][v - 1] = 1;
       }
    }

    dfs();

    for(i = 0 ; i < n ; i++) {
        printf("%d %d %d\n",i + 1, d[i], f[i]);
    }

   /* printf("time:%d\n", time); */ 
    return 0;
}


void dfs()
{
    int i;
    for( i = 0 ; i < n ; i++) {
        color[i] = WHITE;
    }
    for(i = 0 ; i < n ; i++) {
        if(color[i] == WHITE) {
            visit(i);
        }
    }
}

void visit(int i) {
    int j;
    color[i] = GRAY;
    d[i] = ++time;
    for(j = 0 ; j < n ; j++) {
        if(map[i][j] == 0) {
            continue;
        } 
        if(color[j] == WHITE) {
            visit(j);
        }
    }
    color[i] = BLACK;
    f[i] = ++time;
}
