#include <stdio.h>
#define M 100
#define I (1<<21)
int A[M][M],n,d[M];
int queue[M],head=0,tail=0;

int dequeue(){
    int v;
    v=queue[head];
    if(head + 1 == M)head=0;
    else head++;
    return v;
}

void enqueue(int x){
    queue[tail]=x;
    if(tail+1==M)tail=0;
    else tail++;
}

int empty(){
    if(head==tail)return 1;
    else return 0;
}

void bfs(int s){
    int i,j,k;

    enqueue(s);

    for(i=0;i<n;i++){
        d[i]=I;
        }
    d[s]=0;

    while(empty()!=1){
        k=dequeue();
        for(j=0;j<n;j++){
            if(A[k][j] == 0)continue;
            if(d[j]!=I)continue;
            d[j]=d[k]+1;
            enqueue(j);
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",i+1);
        if(d[i]==I){
            printf("-1\n");
        }
	else  printf("%d\n",d[i]);
    }
    }

int main(){
    int i,j,u,k,v;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            A[i][j]=0;
        }
    }

    for(i=0;i<n;i++){
        scanf("%d%d",&u,&k);
        u--;
        for(j=0;j<k;j++){
            scanf("%d",&v);
            v--;
            A[u][v]=1;
        }
    }
    bfs(0);

    return 0;
}

