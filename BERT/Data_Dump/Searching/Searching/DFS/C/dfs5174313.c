#include<stdio.h>

int a=1,cc[101],c[101],f[101][101],d[101]={0},n;


#include<stdio.h>

int main(){
  int k,u,i,j,V;
  
  scanf("%d",&n);
  
  for(i=0;i<=n-1;i++)
    for(j=0;j<=n-1;j++)
      f[i][j]=0;
  for(i=0;i<=n-1;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<=k-1;j++){
      scanf("%d",&V);
       f[u-1][V-1]=1;      
    }}
    
  for(i=0;i<=n-1;i++)
  if(d[i]==0) visit(i);
  for(i=0;i<=n-1;i++)
    printf("%d %d %d\n",i+1,cc[i],c[i]);
   
  return 0;
}

void visit(int u){
  int V; 
  
  cc[u]=a++;
  d[u]=1;
  
  for(V=0;V<=n-1;V++){
    if(f[u][V]==1&&d[V]==0){ 
      visit(V);
    }}
    
  c[u]=a++;  
}
