#include <stdio.h>


int time=0;
int f[101];
int d[101];
int dd[101];
int ff[101];
int Adj[101][101];
int color[101];

void dfs(int);
void visit(int,int);

int main(){
  int n,i,j,k,N,K;

  scanf("%d",&n);

  //初期化
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      Adj[i][j]=0;
      color[i]=0;
      dd[i]=0;
      ff[i]=0;
    }
  }

			
  for(i=1;i<=n;i++){
    scanf("%d",&N);
    scanf("%d",&k);

    for(j=1;j<=k;j++){
      scanf("%d",&K);
      Adj[N][K]=1;
    }
  }


  color[1]=1;
  dfs(n);

   for(i=1;i<=n;i++){
       printf("%d %d %d\n",i,d[i],f[i]);
   }




  return 0;
}


void dfs(int n){
  int i,j;
  for(i=1;i<=n;i++){

    for(j=1;j<=n;j++){
      if(Adj[i][j]==1){
	if(color[j]==0){
	  if(dd[i]!=1){
	    d[i]=++time;
	    dd[i]=1;
	  }
	  //	  printf("dfs %d %d\n",i,d[i]);
	  visit(j,n);
	}
      }
    }

    if(ff[i]!=1){
      f[i]=++time;
      ff[i]=1;
    }
      
  
  }

}

void visit(int u,int n){
  int i;
  // printf("%d\n",u);
  color[u]=1;
  d[u]=++time;
  // printf("visit d %d %d\n",u,d[u]);
  for(i=1;i<=n;i++){
    if(Adj[u][i]==1)
      if(color[i]==0)
	visit(i,n);
  }
  color[u]=2;

  if(ff[u]!=1){
    f[u]=++time;
    ff[u]=1;
  }


  //  printf("visit f %d %d\n",u,f[u]);

  }
