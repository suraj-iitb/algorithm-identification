#include<stdio.h>
#include<stdlib.h>
 
#define N 101
#define BLACK 200
#define WHITE 201
#define GRAY 202
void DFS();
void DFS_Visit(int );
int t =0,num = 0;
int d[N],f[N],color[N],num4[N][N];
 
 
int main(){
  int i,j,num2,num3,num5,flag;
  scanf("%d",&num);
  
  for(i=1;i<=num;i++){
    for(j=1;j<=num;j++){
      num4[i][j] = 0;
    }
  }
  
   for(i=1;i<=num;i++){
     scanf("%d",&num5);
     scanf("%d",&num2);
     if(num2 == 0)continue; 
     else{
       for(j=0;j<num2;j++){
     scanf("%d",&num3);
     num4[i][num3] = 1; 
       }
     }   
   }
 
   DFS();
   for(i=1;i<=num;i++){
     printf("%d %d %d\n",i,d[i],f[i]);
   }
    
    
   return 0;
}
void DFS(){
  int i;
  for(i=1;i<=num;i++){
    color[i]=WHITE;
  }
  t = 0;
   
  for(i=1;i<=num;i++){
    if(color[i]==WHITE){
      DFS_Visit(i);
    }
  }
   
}
 
void DFS_Visit(int u){
  int v,j;
  color[u] = GRAY;
  t += 1;
  d[u] = t;
  for(j=1;j<=num;j++){
    if(color[j] == WHITE && num4[u][j] == 1)DFS_Visit(j);
  }
  color[u] = BLACK;
  t++;
  f[u] = t;
   
}
