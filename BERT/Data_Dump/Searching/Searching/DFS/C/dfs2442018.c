#include <stdio.h>
#include <math.h> 
#define WHITE 0
#define GRAY 1
#define BLACK 2

void DFS_init(void);
void DFS(int id);

int n,Adj[100][100];
int color[100],d[100],f[100],time;

int main()
{
  int i,j,id,k,v;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      Adj[i][j]=0;
  
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
    id--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      Adj[id][v]=1;
    }
  }
  DFS_init();

  return 0;
}

void DFS_init(void)
{
  int id;

  for(id=0;id<n;id++) color[id]=WHITE;  
  time=0;
  
  for(id=0;id<n;id++)
    if(color[id]==WHITE) DFS(id);
  
  for(id=0;id<n;id++) printf("%d %d %d\n",id+1,d[id],f[id]);
}

void DFS(int id)
{
  int v;

  color[id]=GRAY;
  d[id]=++time;

  for(v=0;v<n;v++){
    if(Adj[id][v]==0) continue;
    if(color[v]==WHITE) DFS(v);
  }
  color[id]=BLACK;
  f[id]=++time;
}
