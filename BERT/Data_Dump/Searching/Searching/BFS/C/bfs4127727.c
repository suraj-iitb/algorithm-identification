#include <stdio.h>
#include <stdlib.h>
#define N 100
#define INF 5000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,u,k;
int head = 0,tail = 0;
int queue[N],color[N],d[N];

int M[N][N];

void enqueue(int u);
int dequeue(void);
void bfs(void);/*引数*/

int main()
{
    int i,j,v;
    
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%d %d",&u,&k);
        u--;
        for(j = 0;j < k;j++){
            scanf("%d",&v);
            v--;
            M[u][v] = 1;
        }
    }
    bfs();
    
    for(i = 0;i < n;i++){
        if(d[i] == 5000) printf("%d %d\n",i+1,-1);
        else printf("%d %d\n",i+1,d[i]);
    }
    
    return 0;
}

void bfs(void)
{
    int i,q;
    for(i = 0;i < n;i++){
        color[i] = WHITE;
        d[i] = INF;
    }
    color[0] = GRAY;
    d[0] = 0;
    enqueue(0);
    while(head != tail){
        q = dequeue();
        for(i = 0;i < n;i++){
            if(M[q][i] == 1){
                if(color[i] == WHITE){
                    color[i] = GRAY;
                    d[i] = d[q] + 1;
                    enqueue(i);
                }
            }
        }
        color[q] = BLACK;
    }
}

void enqueue(int u)
{
    int next = (tail+1)%N;
    if(next == head){
        printf("Queue overflow\n");
        exit(1);
    }
    queue[tail] = u;
    tail = next;
}

int dequeue(void)
{
    int val;
    
    if(head == tail){
        printf("Queue empty\n");
        exit(2);
    }
    val = queue[head];
    head = (head+1)%N;
    return val;
}



