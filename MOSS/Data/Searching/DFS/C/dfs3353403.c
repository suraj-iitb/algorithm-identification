#include<stdio.h>
 
#define N 101
 
int num,M[N][N];
int color[N],d[N],f[N],T;
 
void visit(int);
 
int main(){
  int i,j,v,next,k;
 
  scanf("%d",&num);
 
  for(i=0;i<num;i++){
    color[i] = 0;
      for(j=0;j<num;j++){
    M[i][j] = 0;;
      }
  }
     
  for(i = 0;i<num;i++){
    scanf("%d %d",&v,&k);
    for(j=0;j<k;j++){
      scanf("%d",&next);
      M[v-1][next-1] = 1;
    }
  }
  for(i = 0;i<num;i++){
    if(color[i]==0)visit(i);
  }
 
  for(i=0;i<num;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}
 
void visit(int u){
 
  int i;
  color[u]=1;
  d[u]=++T;
  for(i=0;i<num;i++){
    if(M[u][i] == 0)continue;
      if(color[i] == 0)visit(i);
    }
    
    
  color[u] = 2;
  f[u] = ++T;
}
  
