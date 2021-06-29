#include <stdio.h>
#define N 130

#define WHITE 0
#define BLACK 1
#define GRAY 2


int f[N],d[N],f[N],e[N];
int color[N];
int time;
int a[N],b[N],c[N];
int B[N][N];



main()
{
  
  
  int n,i,j,u;
  int A[N][N];
  
  
  
  scanf("%d",&n);
  
  for(i = 1; i <= n; i++){
    scanf("%d%d",&a[i],&b[i]);
    for(j = 1; j <= b[i]; j++){
      scanf("%d",&c[j]);
      A[a[i]][c[j]] = BLACK;
      B[a[i]][j] = c[j];
    }  
  }
  
  dfs(n);

  return 0;
}



int dfs(int n)
{

  int i,u;

  for(i = 1; i <= n; i++){
    u = a[i];
    color[u] = WHITE;
    time = 0;
  }
  
  for(i = 1; i <= n; i++){
    u = a[i];
    if(color[u] == WHITE){
      Visit(u);
    }
    printf("%d %d %d\n",u,d[u],f[u]);
  }
}

int Visit(int u)
{
  
  int i,v;
 
  color[u] = GRAY;
    d[u] = ++time;

    for(i = 1; i <= b[u]; i++){
      v = B[u][i];
      if(color[v] == WHITE){
	Visit(v);
      }
    }
    color[u] = BLACK;
    f[u] = ++time;

 
}
