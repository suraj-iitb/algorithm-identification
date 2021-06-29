#include <stdio.h>
  
#define W 0
#define G 1
#define B 2
#define M 105
 
int Color[M];
int d[M],f[M],Adj[M][M],mu[M];
int time = 0;
 
void DFS(int q)
{
   
  int i;
 
  Color[q] = G;
  d[q] = ++time;
   
  for(i = 0 ; i < mu[q] ; i++){
 
    if(Color[Adj[q][i]] == W){
      DFS(Adj[q][i]);
    }
 
  }
   
  Color[q] = B;
  f[q] = ++time;
   
}
 
int main(){
 
  int n,i,j,Tmp;
  
  for(i = 0 ; i < M ; i++){
      Color[i] = W;
    }
   
  scanf("%d",&n);
   
  for(i = 1 ; i <= n ; i++){
     
      scanf("%d",&Tmp);
      scanf("%d",&mu[i]);
 
      for(j = 0 ; j < mu[i] ; j++){
      scanf("%d",&Adj[i][j]);
      }
  }
   
  for(i = 1 ; i <= n ; i++){
    if(Color[i] == W){
    DFS(i);
      }
  }
   
  for(i = 1 ; i <= n ; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
   
  return 0;
}
