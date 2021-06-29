#include<stdio.h>
#define N 101
#define INF -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,G[N][N]={},d[N]={};
int color[N];
int Q[N];
int head,tail;

void enqueue(int s){
    Q[tail]=s;
    tail=tail+1;
}

int dequeue(void){
    int x=Q[head];
    head=head+1;
    return x;
}

void bfs(int s){
    int i,u;
    for(i=1;i<=n;i++){
        color[i]=WHITE;
        d[i]=INF;
    }
    color[s]=GRAY;
    d[s]=0;
    enqueue(s);
    while(head!=tail){
        u=dequeue();
        int v;
        for(v=1;v<=n;v++){
            if(G[u][v]==1){
            if(color[v]==WHITE){
                color[v]=GRAY;
                d[v]=d[u]+1;
                enqueue(v);
            }
        }
        }
        color[u]=BLACK;
    }
}

int main(){
    int i,j,x;
    int id,a;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&id,&a);
        for(j=0;j<a;j++){
            scanf("%d",&x);
            G[id][x]=1;
        }
    }
    bfs(1);
    for(i=0;i<n;i++){
        printf("%d %d\n",i+1,d[i+1]);
    }
    return 0;
}

