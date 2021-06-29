#include <stdio.h>

#define M 101

int dfs(int, int);

int node[M][M];
int time[M][2];
int visit[M];

int main(void)
{
    int n, u, k;
    int t;
    int i, j;
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d%d", &u, &k);
        
        node[u][0] = k;
        for (j = 1; j <= k; j++){
            scanf("%d", &node[u][j]);
        }
    }
    
    t = 0;
    for (i = 1; i <= n; i++){
        if (visit[i] == 0){
            t = dfs(i, t + 1);
        }
    }
    
    for (i = 1; i <= n; i++){
        printf("%d %d %d\n", i, time[i][0], time[i][1]);
    }
    
    return 0;
}

int dfs(int n, int t)
{
    int i;
    
    visit[n] = 1;
    
    if (time[n][0] == 0){
        time[n][0] = t;
    }
    for (i = 1; i <= node[n][0]; i++){
        if (node[n][i] != 0 && visit[node[n][i]] == 0){
            t = dfs(node[n][i], t + 1);
        }
    }
    t++;
    time[n][1] = t;
    
    return t;
}
