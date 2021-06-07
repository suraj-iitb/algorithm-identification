#include <stdio.h>
#define cent 100
#define INF 100000000

int Graph[cent+1][cent+1], care[cent+1], size[cent+1];

void depthFirstSearch(int pi, int time);

int main(){
    int u, n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i)
    {
        care[i] = INF;
        scanf("%d", &u);
        scanf("%d", &size[u]);
        for(int j = 1; j <= size[u]; ++j) scanf("%d", &Graph[u][j]);
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
