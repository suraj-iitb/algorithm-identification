#include<stdio.h>

int color[101], n, d[101], f[101], v[101][101], time;

 void visit(int u){
  int i;

  color[u] = 1;
  d[u] = ++time;
  for(i=1;i<=n;i++){


   if(color[i] == 0&&v[u][i]==1)visit(i);
   }
  color[u]=2;
  f[u] = ++time;
}

  void dfs(){
  int i;

  for(i=1;i<=n;i++){

   color[i]=0;
   }
  time=0;
  for(i=1;i<=n;i++){
    if(color[i]==0)visit(i);
   }
}

 int main(){


   int i,j,k[101],u[101],l;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      v[i][j]=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d %d",&u[i],&k[i]);
    for(j=1;j<=k[i];j++){
     scanf("%d",&l);
      v[i][l] = 1;
   }
}
   dfs();


    for(i=1;i<=n;i++){
      printf("%d %d %d\n",u[i],d[i],f[i]);
   }
    return 0;
}
