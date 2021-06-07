#include<stdio.h>
#define N 501

static const int INFTY = (1<<21);
static const int A = 0;
static const int B = 1;
static const int C = 2;

int n, M[N][N];
int a[N], d[N], f[N], tt;

void dfs_visit(int u);
void dfs();

int main(){
  int u,k,v; 
  int i,j;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)M[i][j]=0;
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  
  dfs();

  return 0;
}

void dfs_visit(int u){
  int v;
  a[u]=B;
  tt++;
  d[u]=tt;
  for(v=0;v<n;v++){
    if(M[u][v]==0)continue;
    if(a[v]==A){
      dfs_visit(v);
    }
  }
  a[u] = C;
  f[u] = ++tt;
}

void dfs(){
  int i,u;
  for(i=0;i<n;i++)a[i]=A;
  tt=0;
  for(u=0;u<n;u++){
    if(a[u]==A)dfs_visit(u);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}

