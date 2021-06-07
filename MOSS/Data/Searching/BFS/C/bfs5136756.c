#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int queue[MAX], color[MAX], M[MAX][MAX], d[MAX];
int end, top;

void enqueue(int n)
{
    if (end == MAX)
    {
        end = 0;
    }
    queue[end] = n;
    end++;
}

int dequeue()
{
    int val;
    if (top == MAX)
    {
        top = 0;
    }
    val = queue[top];
    top++;
    return val;
}

void bfs(int s, int f)
{
    int u, c = 0;
    enqueue(s);
    while (end != top)
    {
        u = dequeue();
        color[u] = BLACK;
        while (M[u][c] != 0)
        {
            if (color[M[u][c]] == WHITE)
            {
                enqueue(M[u][c]);
                color[M[u][c]] = GRAY;
                d[M[u][c]] = d[u] + 1;
            }
            c += 1;
        }
        c = 0;
    }
}

int main()
{
    int c = 0, n, v, id, num;
    scanf("%d", &n);
    for (c = 0; c < n; c++)
    {
        scanf("%d %d", &id, &num);
        for (v = 0; v < num; v++)
        {
            scanf("%d", &M[id][v]);
        }
    }
    bfs(1, 0);
    for (v = 0; v < n; v++)
    {
        if (d[v + 1] != 0 || v == 0)
        {
            printf("%d %d\n", v + 1, d[v + 1]);
        }

        else
        {
            printf("%d %d\n", v + 1, -1);
        }
    }

    return 0;
}

