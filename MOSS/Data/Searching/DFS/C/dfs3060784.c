#include<stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,t;
int color[N],d[N],f[N];
int M[N][N];

void idfs(int);

void dfs();

int main(){
  int i,j,v,u,k;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      M[u-1][v-1]=1;
    }
  }

  dfs();
  return 0;
}

void idfs(int u){
  int v;

  color[u]=GRAY;
  d[u]=++t;

  for(v=1;v<n;v++){
    if(M[u][v]==0){
      continue;
    }
    if(color[v]==WHITE){
      idfs(v);
    }
  }

  color[u]=BLACK;
  f[u]=++t;

}

void dfs(){
  int i;

  for(i=0;i<n;i++){
    color[i]=WHITE;
  }
  
  t=0;
  for(i=0;i<n;i++){
    color[i]=WHITE;
  }

  t=0;
  for(i=0;i<n;i++){
    if(color[i]==WHITE){
      idfs(i);
    }
    }

    for(i=0;i<n;i++){
      printf("%d %d %d\n",i+1,d[i],f[i]);
}
}


    
    
  

