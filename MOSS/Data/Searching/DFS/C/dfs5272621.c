#include <stdio.h>
#define MAX 200
int a[MAX][MAX];
int out[MAX][3];
int n, step = 0;
int stack[MAX];
int top = 0;

void print_stack()
{
    for (int i = 0; i < top; i++)
    {
        if (i) printf(" ");
        printf("%d", stack[i]);
    }
    printf("\n");
}


void dfs(int k)
{
    
    stack[top++] = k;
    while (top)
    {
        
        int cur = stack[top-1];
        // 如果已经进出过, 那就直接跳过, 出现这种情况是因为后面的节点路过了前面入栈的节点
        if (out[cur][1] && out[cur][2])
        {
            top--;
            continue;
        }
        // 因为进入过的就不会新入栈了, 所以如果当前节点进入过还没出, 现在又碰到的话, 就是结束退出了
        else if (out[cur][1] && !out[cur][2])
        {
            top--;
            out[cur][2] = ++step;
            continue;
        }
        // 全新的节点
        else
        {
            // flag用来判断当前是否死路
            int flag = 0;
            out[cur][1] = ++step;
            for (int i = n-1; i >= 0; i--)
            {
                if (a[cur][i] == 1 && out[i][1] == 0)
                {
                    flag = 1;
                    stack[top++] = i;
                    
                }
            }
            // 当前节点已经到死路了
            if (!flag)
            {
                top--;
                out[cur][2] = ++step;
            }
        }

    }
}


int main(void)
{
    // 初始化数据
    
    // freopen("data.in", "r", stdin);
    int no, k, v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // past[i] = 0;
        out[i][0] = i + 1;
        for (int j = 1; j < 3; j++) out[i][j] = 0;
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

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (j) printf(" ");
    //         printf("%d", a[i][j]);
    //     }
    //     printf("\n");
    // }

    // dfs
    for (int i = 0; i < n; i++)
    {
        if (out[i][1] == 0) dfs(i);
    }
    
    // 输出
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j) printf(" ");
            printf("%d", out[i][j]);
        }
        printf("\n");
    }
    // fclose(stdin);
    return 0;
}
