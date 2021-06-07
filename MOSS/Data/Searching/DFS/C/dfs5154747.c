#include<stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int time;
int G[MAX][MAX];


void dfs(int,int *,int *,int *);
void visit(int,int,int*,int *,int *);

int main()
{
  int i,j,N,u,v,a,b,c;
  int d[MAX],f[MAX],color[MAX];

  scanf("%d",&N);

  for(i=1;i<=N;i++){
    for(j=1;j<=N;j++){
      G[i][j]=0;
    }
  }

  for(i=0;i<N;i++){

    scanf("%d%d",&a,&b);

    for(j=0;j<b;j++){

      scanf("%d",&c);
      G[a][c]=1;
      
    }
  }

  dfs(N,d,f,color);

  for(i=1;i<=N;i++) printf("%d %d %d\n",i,d[i],f[i]);

  return 0;
}

void visit(int n,int v,int d[],int f[],int color[]) 
{
  int i;
  color[v]=GRAY;
  d[v]=++time;

  for(i=1;i<=n;i++){
    if(G[v][i] && color[i]==WHITE) visit(n,i,d,f,color);
  }

  color[v]=BLACK;
  f[v]=++time;

}

void dfs(int n,int d[],int f[],int color[])
{
  int i;
  
  for(i=1;i<=n;i++) color[i]=WHITE;

  time=0;

  for(i=1;i<=n;i++){

    if(color[i]==WHITE) visit(n,i,d,f,color);
  }
}

