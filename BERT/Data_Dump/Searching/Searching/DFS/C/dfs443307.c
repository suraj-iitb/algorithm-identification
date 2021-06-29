/* B Depth First Search */

#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int time;
int A[101][101]; /* 1<= n <= 100 */
int color[101];
int d[101],f[101];

void DFS();
void DFS_Visit(int u);

int main(){
  int i,j;
  int u,k,v;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    d[i]=0;
    f[i]=0;
    for(j=1;j<=n;j++){
      A[i][j]=0;
    }
  }
  

  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      A[u][v]=1;
    }
  }
  
  DFS();

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  

  return 0;
}

void DFS(){
  int i;

  for(i=1;i<=n;i++){
    color[i]=WHITE;
  }
  
  time = 0;
  
  for(i=1;i<=n;i++){
    if(color[i]==WHITE){
      DFS_Visit(i);
    }
  }
}

void DFS_Visit(int u){
  int i;
  color[u]=GRAY;
  time=time+1;
  d[u]=time;
  for(i=1;i<=n;i++){
    if(A[u][i]==1){ /* check array element */
      if(color[i]==WHITE){
	DFS_Visit(i);
      }
    }
  }
  color[u]=BLACK;
  time=time+1;
  f[u]=time;
}
    
