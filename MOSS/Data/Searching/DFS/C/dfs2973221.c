
#include <stdio.h>
#define MAX 101
void Search(int);
 
int number,G[MAX][MAX],d[MAX],count=0;
int F[MAX] = {0};
 
  
int main(void){
  int i,j,k,u,a;
   
  for(i = 0;i < number;i++){
    d[i] = 0;
  }
    
  scanf("%d",&number);
   
  for(i = 0;i < number + 1;i++){
    for(j = 0;j < number + 1;j++){
      G[i][j] = 0;
    }
  }
   
  for(i = 0;i < number;i++){
   
    scanf("%d %d ",&k,&u);
   
    for(j = 0;j < u;j++){
      scanf("%d",&a);
      G[k - 1][a - 1] = 1;
    }
  }
  
  for(i = 0;i < number;i++){
    if(d[i] == 0)
    Search (i);
  }
       
  for(i = 0;i < number;i++){
    printf("%d %d %d\n",i+1,d[i],F[i]);
  }
  
  return 0;
 }
 
 
void Search(int u){
  int v;
  count++;
  d[u] = count;
   
  for(v = 0;v < number;v++){
    if(G[u][v] == 1 && d[v] == 0 ){
      Search(v);
    }
  }
  count++;
  F[u] = count;
}

