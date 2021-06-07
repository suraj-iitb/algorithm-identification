#include<stdio.h>
#define YOSHI 100
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define NIL -1

int M[YOSHI][YOSHI],a[YOSHI],b[YOSHI],n;
int queue[YOSHI],head = 0,tail  = 0;

int deq(){
    head++;
    if(head == YOSHI){
        head = 0;
        return queue[YOSHI - 1];
    }
    return queue[head - 1];
}
void enq(int u){
    queue[tail++] = u;
    if(tail == YOSHI) tail = 0;
}

void bfs(){
    int i,u = 0;
    for(i = 0;i < n;i++){
        a[i] = WHITE;
        b[i] = NIL;
    }
    b[u] = 0;
    a[u] = GRAY;
    enq(u);
    
    while(head != tail){
        u = deq();
        for(i = 0;i < n;i++){
            if(M[u][i] == 1 && a[i] == WHITE){
                enq(i);
                a[i] = GRAY;
                b[i] = b[u] + 1;
            }
        }
        a[u] = BLACK;
    }
}

int main(){
    int i,j,u,k,l;
    scanf("%d",&n);
    
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            M[i][j] = 0;
        }
    }
    for(i = 0;i < n;i++){
        scanf("%d",&u);
        scanf("%d",&k);
        for(j = 0;j < k;j++){
            scanf("%d",&l);
            M[u - 1][l - 1] = 1;
        }
    }
    bfs();
    
    for(i = 0;i < n;i++) printf("%d %d\n",i+1,b[i]);
    return 0;
}
