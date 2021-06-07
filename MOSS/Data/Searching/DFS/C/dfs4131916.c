#include<stdio.h>

#define N 100
#define WHITE 0
#define BLACK 2
#define GRAY 1

int A[N][N],S[N],d[N],f[N],color[N];
int top=0,time,n;

void visit(int u){
  int i;
  
  color[u]=GRAY;
  d[u]=++time;
  for(i=0;i<n;i++){
    if(A[u][i]==0) continue;
    if(color[i]==WHITE) visit(i);
  }

  color[u]=BLACK;
  f[u]=++time;
}


int main(){
  int u,v,k,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]=0;
    }
  }
  
  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      A[u][v]=1;
    }
  }
  
  /*dfs*/
  for(i=0;i<n;i++){
    color[i]=WHITE;
  }

  time=0;

  for(i=0;i<n;i++){
    if(color[i]==WHITE) visit(i);
  }

  /*表示*/

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}

