#include<stdio.h>
#define N 100
#define MAX 40000000

int n,M[N][N];
int d[N];
int atama,siri;
int A[MAX];

void bfs(int s){
    int i,u;
    A[siri]=s;
    siri++;
    for(i=0;i<n;i++)d[i]=-1;
    d[s]=0;
    while(atama!=siri){
        u=A[atama];
        atama++;
        for(i=0;i<n;i++){
            if(M[u][i]==0)continue;
            if(d[i]!=-1)continue;
            d[i]=d[u]+1;
            A[siri]=i;
            siri++;
        }
    }
    for(i=0;i<n;i++){
        printf("%d %d\n",i+1,d[i]);

    }
}

int main(){
    int i,u,k,v,j;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            M[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        scanf("%d",&u);
        scanf("%d",&k);
        u--;
        for(j=0;j<k;j++){
            scanf("%d",&v);
            v--;
            M[u][v]=1;
        }
    }
    bfs(0);

    return 0;
}

