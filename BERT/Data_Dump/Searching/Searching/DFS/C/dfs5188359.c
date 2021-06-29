#include<stdio.h>

int n,M[100][100],color[100],d[100],f[100],tt;

void visit(int u){
  int i;
  color[u]=1;
  d[u]=++tt;
  for(i=0;i<n;i++){
    if(M[u][i]==0)continue;
    if(color[i]==0){visit(i);}}
    color[u]=2;
    f[u]=++tt;}

void defs(){
  int u;
  for(u=0;u<n;u++){color[u]==0;}
  tt=0;

  for(u=0;u<n;u++){
    if(color[u]==0){visit(u);}}
    for(u=0;u<n;u++){
      printf("%d %d %d\n",u+1,d[u],f[u]);}
}

int main(){
  int i,j,u,v,k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){M[i][j]=0;}
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;}}
  defs();
  return 0;}
  

