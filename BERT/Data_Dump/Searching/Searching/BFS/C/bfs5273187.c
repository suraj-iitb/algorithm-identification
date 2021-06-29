#include <stdio.h>
#define MAX 105
int a[MAX][MAX];
int out[MAX][2];
int n;
int queue[MAX];
int head = 1;
int tail = 0;

void enqueue(int k)
{
    queue[head] = k;
    head = (head + 1) % MAX;
}

int deque()
{
    tail = (tail + 1) % MAX;
    return queue[tail];
    
}

int isQueueEmpty()
{
    return (tail + 1) % MAX == head;
}

void bfsRec(int start, int step)
{
    // 如果
    out[start][1] = step;
    for (int i = 0; i < n; i++)
    {
        if (a[start][i] == 1 && (out[i][1] == -1 || out[i][1] > step+1))
        {
            bfsRec(i, step+1);
        }
    }
}

void bfs()
{
    enqueue(0);
    out[0][1] = 0;
    while(!isQueueEmpty())
    {
        int cur = deque();
        for (int i = 0; i < n; i++)
        {
            if (a[cur][i] == 1 && (out[i][1] == -1 || out[i][1] > out[cur][1] + 1))
            {
                out[i][1] = out[cur][1] + 1;
                enqueue(i);
            }
        }

    }
}

int main(void)
{
    // 初始化数据
    int no, k, v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // past[i] = 0;
        out[i][0] = i + 1;
        out[i][1] = -1;
        for (int j = 0; j < n; j++) a[i][j] = 0;
    }

    // 读取邻接表
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &no, &k);
        while(k--)
        {
            scanf("%d", &v);
            a[i][v-1] = 1;
        }
    }

    // bfs
    // bfs();
    bfsRec(0, 0);
    // 输出
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j) printf(" ");
            printf("%d", out[i][j]);
        }
        printf("\n");
    }
    return 0;
}
