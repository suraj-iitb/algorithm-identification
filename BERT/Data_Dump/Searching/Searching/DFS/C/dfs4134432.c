#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n,M[100][100],color[100],d[100],f[100],t;
void depthfv(int);
void depth(void);
int main(){
  int i,j,k,l,m;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&k,&l);
    k--;
    for(j=0;j<l;j++){
      scanf("%d",&m);
      m--;
      M[k][m]=1;
    }
  }
  depth();
  return 0;
}
void depthfv(int u){
  int i;
  color[u]=GRAY;
  d[u]=++t;
  for(i=0;i<n;i++){
    if(M[u][i]==0)continue;
    if(color[i]==WHITE){
      depthfv(i);
    }
  }
  color[u]=BLACK;
  f[u]=++t;
}
void depth(){
  int i;
  for(i=0;i<n;i++)color[i]=WHITE;
  t=0;
  for(i=0;i<n;i++){
    if(color[i]==WHITE)depthfv(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}

