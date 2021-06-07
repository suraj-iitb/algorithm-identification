#include <stdio.h>

#define N 100

static const int white = 0;
static const int gray = 1;
static const int brack = 2;

void dfs(int);
void visit(int,int);

int A[N][N],color[N],time,d[N],f[N];


int main()
{
  int n,i,j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j] = 0;
    }
  }
    for(i=0;i<n;i++){
      scanf("%d %d",&u,&k);
      u--;
      for(j=0;j<k;j++){
	scanf("%d",&v);
	v--;
	A[u][v] = 1;
      }
    }
    //printf("%d",n);
    dfs(n);

    return 0;

  }

void dfs(int n)
{
  int u;

  for(u=0;u<n;u++){
    color[u] = white;
  }
  time = 0;
  for(u=0;u<n;u++){
    if(color[u] == white) visit(u,n);
  }

  for(u=0;u<n;u++) printf("%d %d %d\n",u+1,d[u],f[u]);
 
}

void visit(int u,int n)
{
  int v;

  color[u] = gray;
  d[u] = ++time;

  for(v=0;v<n;v++){
    if(A[u][v] == 0) continue;
    if(color[v] == white) visit(v,n);
  }
  color[u] = brack;
  f[u] = ++time;
}


    

