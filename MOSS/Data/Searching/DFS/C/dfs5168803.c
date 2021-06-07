#include<stdio.h>

void DFS(void);

void visit(int);
#define MAX 10000
#define WHITE 0
#define GRAY 1
#define BLACK 2


int n;


int adj[MAX][MAX];

int color[MAX];

int d[MAX];//discover

int f[MAX];//finish

int time;




int main(){

    int i,j;

    int bango,kosuu,num;

    scanf("%d",&n);

    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){

            adj[i][j] = 0;
        }
    }

    for(i = 0;i < n;i++){

        scanf("%d%d",&bango,&kosuu);

        for(j = 0;j < kosuu;j++){

            scanf("%d",&num);

            adj[bango][num] = 1;

        }
    }



 

    DFS();


}

void DFS(){

    int i;

    for(i = 1;i <= n;i++){

        color[i] = WHITE;
    }

    for(i = 1;i <= n;i++){

        if(color[i] == WHITE){
            visit(i);
        }
    }

    for(i = 1;i <= n;i++){

        printf("%d %d %d\n",i,d[i],f[i]);
    }

}

void visit(int x){

    int MIN,i;

    color[x] = GRAY;

    d[x] = ++time;

    for(i = 1;i <=n;i++){

        if(adj[x][i] == 0)continue;

        if(color[i] == WHITE){

            visit(i);
        }
    }

    color[x] = BLACK;

    f[x] = ++time;


}


