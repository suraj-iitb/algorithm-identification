#include <stdio.h>
#include <stdlib.h>
typedef struct a{
    int queue[100];
    int a,b;
}Queue;

Queue* init(){
    Queue* k = (Queue*)malloc(sizeof(Queue));
    k->a=0;k->b=0;
    return k;
}

void enqueue(Queue* q,int n){
    q->queue[q->b]=n;
    q->b++;
}

int dequeue(Queue* q){
   int n=q->queue[q->a];
   q->a++;
   return n;
}

int main(void){
    int n,i,j,u,k,l,time=0;
    int a[100][100];
    int dist[100];
    Queue* q;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        dist[i]=-1;
        for(j=0;j<n;j++){
            a[i][j] = 0;
        }
    }
    for(i=0;i<n;i++){
        scanf("%d",&u);
        scanf("%d",&k);
        for(j=0;j<k;j++){
            scanf("%d",&l);
            a[u-1][l-1] = 1;
        }
    }
    q = init();
    enqueue(q,0);
    dist[0]=0;
    while(q->a < q->b){
        u = dequeue(q);
        for(i=0;i<n;i++){
            if(a[u][i]==1&&dist[i]==-1){
                enqueue(q,i);
                dist[i]=dist[u]+1;
            }
        }
    }
    
    for(i=0;i<n;i++){
        printf("%d %d\n",i+1,dist[i]);
    }
}
