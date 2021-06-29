#include <stdio.h>
#define N 100
#define White 0
#define Gray 1
#define Black 2

int n,M[N][N],color[N],time=0;
int enter[N],ex[N];
//
void dfs_visit(int u){
  int v;
  color[u]=Gray; //?¨????
    enter[u]=++time;// ?¨??????????
  for(v=0;v<n;v++){
    if(M[u][v]==0)continue;//?????????????????´???
    if(color[v]==White){//????¨??????????
      dfs_visit(v);
    }
  }
  color[u]=Black;
  ex[u]=++time;
}
//
void dfs(){
  int i;
  for(i=0;i<n;i++)color[i]=White;// ?????????
  
  for(i=0;i<n;i++){
    if(color[i]==White)dfs_visit(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,enter[i],ex[i]);
  
  }
}
//
int main(){
  int u,v,k,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;//0 origin    
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;//0 origin
      M[u][v]=1;
    }
  }
  dfs();
  return 0;
}
