#include <stdio.h>
#define N 1000
#define INF 1<<21
 
int n,M[N][N];
int d[N];
int Q[2*N],head=0,tail=0;
 
void enq(int);
int deq(void);
void bfs(int);
 
 
int main(){
    int i,j,u,k,v;
 
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)M[i][j] = 0;
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&u, &k);
        for(j=0;j<k;j++){
            scanf("%d",&v);
            M[u][v] = 1;
        }
    }
    bfs(1);
    for(i=1;i<=n;i++){
        if(d[i] == INF)d[i] = -1;
        printf("%d %d\n",i,d[i]);
    }
    return 0;
 
}
 
void enq(int x){
    Q[tail++] = x;
}
 
int deq(){
    return Q[head++];
}
 
void bfs(int s){
    int i,u,v;
    enq(s);
    for(i=1;i<=n;i++)d[i] = INF;
        d[s] = 0;
    while(head != tail){
        u = deq();
        for(v = 1;v <= n;v++){
            if(M[u][v] == 0)continue;
            if(d[v] != INF)continue;
            d[v] = d[u] + 1;
            enq(v);
        }
    }
}
