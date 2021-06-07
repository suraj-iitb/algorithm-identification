#include<stdio.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs();
void dfs_visit(int);

int n, M[MAX][MAX];
int color[MAX],d[MAX],f[MAX];
int tt;


void dfs(){
  int u;

  for(u=0;u<n;u++){
    color[u] = WHITE;
  }
    tt = 0;

    for(u=0;u<n;u++){
      if( color[u] == WHITE ){
	dfs_visit(u);
      }}
      
      for(u=0;u<n;u++){
	printf("%d %d %d\n", u+1,d[u],f[u]);
      }
  
    
    }

    void dfs_visit(int u){
      int v;
      color[u] = GRAY;
      d[u] = ++tt;
      for(v=0;v<n;v++){
	if(M[u][v]==0){
	  continue;
	}
	if( color[v]== WHITE){
	  dfs_visit(v);
	}
      }
      color[u] = BLACK;
      f[u]= ++tt;
    }                       
  
int main(){
  int i,j;
  int u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;     //  A[1][1] denaku A[0][0]dekanngaeteiru
    
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  dfs();


  return 0;

}


