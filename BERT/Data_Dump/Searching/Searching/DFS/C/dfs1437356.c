#include<stdio.h>
void DFS(int);
void DFSvisit(int);
int a[105][105],color[105],count,time,d[105],f[105],p[105],n;
int main(){
  int i,j,b[105],c,k;
  for(i=0;i<=100;i++){
    d[i]=0;
    f[i]=0;
    for(j=0;j<=100;j++){
      a[i][j]=0;
       
    }
  }
   
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&b[i]);
    scanf("%d",&k);
    for(j=1;j<=k;j++){
      scanf("%d",&c);
      a[b[i]][c]=1;
    }
  }
 
DFS(n);
      for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
      }
return 0;
}
void DFS(int u){
  int i;
  for(i=1;i<=u;i++){
    color[i]=0;
    p[i]=i;
    }
      time=0;
  for(i=1;i<=u;i++){
    if(color[i]==0){
      DFSvisit(i);
    }
  }
}
void DFSvisit(int u)
 {
   int i;
   color[u]=2;
   d[u]= ++time;
   for(i=1;i<=n;i++){
     if(color[i]==0 && a[u][i]==1){
       DFSvisit(i);
     }
   }
   color[u]=1;
   f[u] = ++time;
 }
