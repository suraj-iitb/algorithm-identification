#include <stdio.h>
#define N 105
#define MAX 105
#define BLACK 2
#define GRAY 1
#define WHITE 0
#define NIL -1

int head, tail;
int Q[N];
int color[N];
int discover[N];
int adj[N][N];
int n;

void enqueue(int);
int dequeue();
void bfs(int);

int main()
{

    //int n;
    int u, k, v;
    int i, j;
    int num;
    int uid;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d%d", &uid, &k);
        for (j = 0; j < k; j++)
        {
            scanf("%d", &num);
            adj[uid][num] = 1;
        }
    }
    /*
 for(i=1;i<=n;i++){
   printf("%d  ",i);
    for(j=1;j<=n;j++){
    printf("%d ",adj[i][j]);
  }
    printf("\n");
 }
 printf("\n");
 printf("\n");
 */
    bfs(1);

    for (i = 1; i <= n; i++)
    {
        printf("%d %d\n", i, discover[i]);
    }

    return 0;
}

void enqueue(int num)
{

    Q[tail] = num;
    if (tail + 1 == MAX)
        tail = 0;
    else
        tail++;
}

int dequeue(void)
{
    int x;
    x = Q[head];
    if (head + 1 == MAX)
        head = 0;
    else
        head++;
    return x;
}

void bfs(int node)
{

    int i;
    int uid;

    for (i = 1; i <= n; i++)
    {
        color[i] = WHITE;
        discover[i] = NIL;
    }

    color[node] = GRAY;
    discover[node] = 0;

    enqueue(node);

    while ((tail - head - 1) >= 0)
    {

        uid = dequeue();

        for (i = 1; i <= n; i++)
        {
            if (adj[uid][i] == 1 && color[i] == WHITE)
            {
                color[i] = GRAY;
                discover[i] = discover[uid] + 1;
                enqueue(i);
            }
        }
        color[uid] = BLACK;
    }
}

