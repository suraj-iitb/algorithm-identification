#include<stdio.h>
#define N 101

void bfs();
void visit(int);

int n,G[N][N],BFS[N],d[N];
int queue[N],head,tail;

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
    bfs();
    return 0;
}

void bfs(){
    int i;
    for( i = 1 ; i <= n ; i++ ) BFS[i] = 0;
    d[1] = 0;
    visit(1);
    for( i = 1 ; i <= n ; i++ ){
        printf("%d ",i);
        if( i != 1 && d[i] == 0 ) printf("-1\n");
        else printf("%d\n",d[i]);
    }
}

void visit(int u){
    int i;
    BFS[u] = 2;
    for( i = 1 ; i <= n ; i++ ){
        if( G[u][i] != 1 ) continue;
        if( BFS[i] == 0 ){
            d[i] = d[u] + 1;
            BFS[i] = 1;
            queue[tail++] = i;
        }
    }
    if( head != tail ){
        visit(queue[head++]);
    }
}
