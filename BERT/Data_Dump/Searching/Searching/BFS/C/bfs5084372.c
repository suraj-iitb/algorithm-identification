#include<stdio.h>
#define MAX 100
#define N 100
#define WHITE 0
#define GRAY  1
#define BLACK 2

int head = 0;
int tail = 0;

int que[MAX];
int G[N][N];
char color[N];
int d[N];
int f[N];

void enqueue(int x)
{
    if(head == (tail+1)%MAX)
    {
        printf("OVF\n");
    }
    
    que[tail] = x;
    
    if(tail+1 == MAX)
    {
        tail = 0;
    }
    else
    {
        tail++;
    }
}

int dequeue()
{
    if(head == tail)
    {
        printf("UNF\n");
    }
    
    int x = que[head];
    
    if(head+1 == MAX)
    {
        head = 0;
    }
    else
    {
        head++;
    }
    return x;
}

void BFS(int s, int n)
{
    int i,u;
    
    for(i=0; i<n; i++)
    {
        color[i] = WHITE;
        d[i] = -1;
    }
    
    color[s] = GRAY;
    d[s] = 0;
    enqueue(s);
    
    while(head != tail)
    {
        u = dequeue();
        
        for(i=0; i<n; i++)
        {
            if(G[u][i])
            {
                if(color[i] == WHITE)
                {
                    color[i] = GRAY;
                    d[i] = d[u] + 1;
                    enqueue(i);
                }
            }
        }
        color[u] = BLACK;
    }
}


int main(void)
{
    int n, i, k, u, v, j;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &u, &k);
        
        for(j=0; j<k; j++)
        {
            scanf("%d", &v);
            G[u-1][v-1] = 1;
        }
    }
    
    BFS(0, n);
    
    for(i=0; i<n; i++)
    {
        printf("%d %d\n", i+1, d[i]);
    }
    return 0;
}

