#include<stdio.h>
int i,j,n,v,u,k,time,data[101][101],d[101],f[101];
void visit(int);



int main(){
  time=1;
  scanf("%d",&n);
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      data[i][j]=0;
      d[j]=0;
      f[j]=0;
    }
  }
  for(i = 0; i < n; i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      data[u][v]=1;
    }
  }
  for(i=1;i<=n;i++){
    if(d[i]==0)visit(i);
  }
  for(i = 1;i <= n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}




void visit(int u){
  int v;
  
  d[u]=time++;

  
  
  for(v = 1; v <= n; v++){
    if(data[u][v]&d[v]==0)
      visit(v);
  }
  f[u]=time++;
}

