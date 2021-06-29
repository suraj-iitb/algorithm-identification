#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n,top,tail;
int A[101][101];
int color[101];
int d[101];
int q[101];

void enqueue(int x){
    q[tail++]=x;
}

int dequeue(){
    return q[top++];
}

void bfs(int s){
    int u;
    for(int i=1; i<n+1; i++){
        d[i]=-1;
    }
    d[s]=0;
    color[s]=GRAY;
    enqueue(s);

    while(top!=tail){
        u=dequeue();
        for(int j=1; j<n+1; j++){
            if(A[u][j]==1){
                if(color[j]==WHITE){
                    color[j]=GRAY;
                    d[j]=d[u]+1;
                    enqueue(j);
                }
            }
        }
        color[u]=BLACK;
    }
}
int main(void){
    int u,k;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        scanf("%d %d",&u,&k);
        for(int j=0; j<k; j++){
            int v;
            scanf("%d",&v);
            A[u][v]=1; //頂点をつなぐ
        }
    }
    bfs(1);
    for(int i=1; i<n+1; i++){
        printf("%d %d\n",i,d[i]);
    }
    return 0;
}
