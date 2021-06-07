#include<stdio.h>
#define MAX 10000

void dfs(int);

    int n,t=1;
    int d[MAX],f[MAX];
    int A[MAX][MAX];
    int visit[MAX];

int main(){

    int i,j,u,k,v;

    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            A[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++){
        scanf("%d%d", &u, &k);
        if(k==0) continue;
        for (j = 1; j <= k; j++){
            scanf("%d", &v);
            A[u][v] = 1;
        }
    }

    for(i=1;i<=n;i++) visit[i]=0;
    
    for(i=1;i<=n;i++){
        if(visit[i]==0) dfs(i);//訪れた回数が0の時次に進む
    }

    for(i=1;i<=n;i++){
        printf("%d %d %d\n",i,d[i],f[i]);
    }

    return 0;
}

void dfs(int i){
    int j;
    visit[i]=1;//1度訪れる
    d[i]=t++;
    for(j=1;j<=n;j++){
        if(A[i][j]==0) continue;    //頂点同士が繋がっている時
        if(visit[j]==0) dfs(j);
    }
    visit[i]=2;//2度目
    f[i]=t++;
}
