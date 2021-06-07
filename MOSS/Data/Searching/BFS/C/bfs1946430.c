#include<stdio.h>
 
typedef struct{
    int num;
    int depth;
}node;
 
int head=0;
int tail=0;
node queue[100];
 
int graph[100][100]={0};
 
int isEmpty(void){
    if(head==tail){
        return 1;
    }else{
        return 0;
    }
}
 
void enqueue(node n){
    queue[(head++)%100]=n;
}
 
node dequeue(void){
    return queue[(tail++)%100];
     
}
 
void init(int d[],int n){
    int i;
    d[0]=0;
    for(i=1;i<n;i++){
        d[i]=-1;
    }
}
 
int main(void){
    int n;
    int u,k,v;
    int i,j;
    int d[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&u,&k);
        for(j=0;j<k;j++){
            scanf("%d",&v);
            graph[u-1][v-1]=1;
        }
    }
    /*printf("qa\n");*/
    init(d,n);
    node tmp;
    node next;
    tmp.num=0;
    tmp.depth=0;
    enqueue(tmp);
    while(!isEmpty()){
        tmp=dequeue();
        for(i=0;i<n;i++){
            if(graph[tmp.num][i]&&d[i]==-1){
                d[i]=tmp.depth+1;
                next.num=i;
                next.depth=d[i];
                enqueue(next);
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d %d\n",i+1,d[i]);
    }
    return 0;
}
