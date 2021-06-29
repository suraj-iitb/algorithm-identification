#include <stdio.h>
#define cent 100
#define INF 100000000

int Graph[cent+1][cent+1], care[cent+1], size[cent+1];

void depthFirstSearch(int pi, int time);

int main(){
    int x, n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
    {
        care[i] = INF;
        scanf("%d", &x);
        scanf("%d", &size[x]);
        for(int j = 1; j <= size[x]; ++j) scanf("%d", &Graph[x][j]);
    }

    depthFirstSearch(1, 0);

    for (int i = 1; i <= n; ++i) printf("%d %d\n", i, (care[i] == INF) ? -1 : care[i]);

    return 0;
}

void depthFirstSearch(int pi, int time)
{
    care[pi] = time;
    for(int i = 1; i <= size[pi] ; ++i) if(time+1 < care[Graph[pi][i]]) depthFirstSearch(Graph[pi][i], time+1);
}

