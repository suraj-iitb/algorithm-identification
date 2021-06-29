#include<stdio.h>

#define WHITE -1
#define GRAY 0
#define  BLACK 1

#define N 100

int n,m[N][N];
int c[N];
int d[N],f[N];
int time;

void dfs_init(){
    int i;
    for(i=0;i<n;i++){
        c[i]=WHITE;
    }
}

void dfs(int u){
    int i;
    c[u]=GRAY;
    d[u]=++time;
    
    for(i=0;i<n;i++){
        if(m[u][i] && c[i]==WHITE){
            dfs(i);
        }
    }
    c[u]=BLACK;
    f[u]=++time;
}

int main(){
    int i,j,u,v,k;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            m[i][j]=0;
        }
    }

    for(i=0;i<n;i++){
        scanf("%d%d",&u,&v);
        u--;
        for(j=0;j<v;j++){
            scanf("%d",&k);
            k--;
            m[i][k]=1;
        }
    }

    dfs_init();
    for(i=0;i<n;i++){
        if(c[i]==WHITE) dfs(i);
    }

    for(i=0;i<n;i++){
        printf("%d %d %d\n",i+1,d[i],f[i]);
    }

    return 0;
}

