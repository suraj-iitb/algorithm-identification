#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 100

int n;
int head,tail;
char a[N][N];
int d[N];
char color[N];
int q[N];

void push(int p){
    if((tail+1)%N != head){
        q[tail]=p;
        tail = (tail+1)%N;
    }
    return;
}

int pop(){
    int r = -1;
    if(head != tail){
        r = q[head];
        head = (head+1)%N;
    }
    return r;
}

void bfs(){
    int i,u;
    for(i=1; i<n; i++){
        color[u]=WHITE;
        d[u]=-1;
    }
    color[0]=GRAY;
    d[0]=0;
    
    push(0);
    
    while((u=pop()) != -1){
        for(i=0; i<n; i++){
            if(a[u][i] == 1 && color[i] == WHITE){
                color[i] = GRAY;
                d[i]=d[u]+1;
                push(i);
            }
        }
        color[u]=BLACK;
    }
    return;
}

int main(){
    int i,j,u,k,v;
    scanf("%d",&n);
    
    for(i=0; i<n; i++){
        d[i]=-1;
    }
    
    for(i=0; i<n; i++){
        scanf("%d%d",&u,&k);
        
        for(j=0; j<k; j++){
            scanf("%d",&v);
            a[u-1][v-1]=1;
        }
    }
    bfs();
    for(i=0; i<n; i++){
        printf("%d %d\n",i+1,d[i]);
    }
    return 0;
}
