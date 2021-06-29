#include <stdio.h>
#define N 101
void visit(int);
int T=1,m[N][N],d[N]={0},a[N],b[N],n;
#include<stdio.h>
int main(){
  int k,i,j,u,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      m[i][j]=0;
    }
  }
 for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
       m[u-1][v-1]=1;      
   }
 }
 for(i=0;i<n;i++){
   if(d[i]==0) visit(i);
 }
 for(i=0;i<n;i++){
   printf("%d %d %d\n",i+1,a[i],b[i]);
 }
 return 0;
}
void visit(int u){
  int v; 
  a[u]=T++;
  d[u]=1;
  for(v=0;v<n;v++){
    if(m[u][v]==1&&d[v]==0){ 
      visit(v);
    }
  }   
  b[u]=T++;  
}

