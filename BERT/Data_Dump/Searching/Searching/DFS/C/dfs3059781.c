#include<stdio.h>

int n,t,finder[500],d[500],f[500],P[500][500];

void explorer(int u){
  int v;

  // 0 is yet. 1 is judging. 2 is alleady.

  finder[u]=1; //探索開始
  t++;
  d[u]=t;
  for(v=1;v<=n;v++){
    if(P[u][v]==1){
      if(finder[v]==0) explorer(v);
    }
  }
  t++;
  f[u]=t;
  finder[u]=2; //探索終了
}

int main(){

  //int P[500][500];
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      P[u][v]=1;
    }
  }

  for(i=0;i<n;i++){
    finder[i]=0;
  }

  for(u=1;u<=n;u++){
    if(finder[u] == 0) explorer(u);
  }

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  
  /*
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      printf("%d",P[i][j]);
      if(j!=n) printf(" ");
    }
    printf("\n");
    }*/

  
  
}

