#include<stdio.h>
#define N 101



int G[N][N]={};
int d[N]={},f[N]={};
int n;
int tt=0;



void vis(int pos){

  int i;


  d[pos]=++tt;

  for(i=1;i<=n;i++){
    if(G[pos][i] && d[i]==0)vis(i);
  }

  f[pos]=++tt;

}



void dfs(){

  int i;
  for(i=1;i<=n;i++){
    if(d[i]==0)vis(i);
  }
}






int main(){



  int i,k,u;
  int j,v;



  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      G[u][v]=1;
    }
  }


  /*for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      printf("%d ",G[i][j]);
    }
    printf("\n");
  }*/



  dfs();


  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }



  return 0;
}

