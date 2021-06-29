#include<stdio.h>
 
#define N 101
#define b 2
#define w 0
#define g  1
 
int n=0,z=0,G[N][N],d[N],f[N],c[N];

 

void DFS_Visit(int u);
void DFS();
  
   
 
main(){
  int i,j,s,v,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0; j<n;j++){
      G[i][j] = 0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d", &v,&r);
    for(j=0;j<r;j++){
      scanf("%d",&s);
      G[i][s-1] = 1;
    }
  }
  DFS();
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1, d[i], f[i]);
  }
  return 0;
}




void DFS_Visit(int u){
  int t;
  c[u] = g;
  d[u] = ++z;
  for(t=0;t<n;t++){
    if(G[u][t] == 1 && c[t] == w){
      DFS_Visit(t);
    }
  }
  c[u] = b;
  f[u] = ++z;
}


void DFS(){
  int u;
  z = 0;
  for(u=0;u<n;u++){
    c[u] = w;
  }
  for(u=0;u<n;u++){
    if(c[u] == w){
      DFS_Visit(u);
     }
  }
}  

