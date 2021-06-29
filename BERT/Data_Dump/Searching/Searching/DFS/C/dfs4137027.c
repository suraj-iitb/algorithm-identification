#include<stdio.h>

void DFS(int);
void DFSre(int,int);

int G[100][100],d[100],f[100],judge[100];
int visit=0;

void DFS(int n)
{
  int id;

  for(id=0;id<n;id++)
    judge[id] = 0;

  for(id=0;id<n;id++) {
    if(judge[id] == 0)
      DFSre(id,n);
  }

  for(id=0;id<n;id++)
    printf("%d %d %d\n",id+1,d[id],f[id]);
}

void DFSre(int id,int n)
{
  int a;

  judge[id] = 1;
  d[id] = ++visit;
  
  for(a=0;a<n;a++) {
    if(G[id][a] == 0)
      continue;
    if(judge[a] == 0)
      DFSre(a,n);
  }
  
  judge[id] = 2;
  f[id] = ++visit;
}

  
int main()
{
  int n,x,y,z,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      G[i][j] = 0;
    }
  }

  for(i=0;i<n;i++) {
    scanf("%d%d",&x,&y);
    x--; /* 行列用に-1 */
    for(j=0;j<y;j++) {
      scanf("%d",&z);
      z--; /* 行列用に-1 */
      G[x][z] = 1;
    }
  }

  DFS(n);

  return 0;
}
      
      

