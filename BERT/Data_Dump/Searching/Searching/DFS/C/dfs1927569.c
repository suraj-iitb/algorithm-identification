#include<stdio.h>
#include<stdlib.h>

#define BLACK 0
#define GRAY 1
#define WHITE 2

int tt;
int st[101];
int et[101];
int num[101][101];

void dfs(int*,int);
void visit(int*,int,int);

int main(){
  int i,j;
  int n,m,l,v;
  int color[101];

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      num[i][j]=0;
    }
  }/*?????????*/

  for(i=1;i<=n;i++){
    scanf("%d%d",&v,&m);
    for(j=1;j<=m;j++){
      scanf("%d",&l);
      num[v][l]=1;
    }
  }

  dfs(color,n);

  return 0;
    
}

  
void dfs(int *color,int n){
  int i,j;
  for(i=1;i<=n;i++){
    color[i]=WHITE;
  }

  tt=0;

  for(i=1;i<=n;i++){
	if(color[i]==WHITE){
	  visit(color,n,i);
	}
    }
  
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,st[i],et[i]);
  }

}

void visit(int *color,int n,int i){
  int j;
  color[i]=GRAY;
  st[i]=++tt;

  for(j=1;j<=n;j++){
    if(num[i][j]==0) continue;
    if(color[j]==WHITE) visit(color,n,j);
  }

  color[i]=BLACK;
  et[i]=++tt;
    
}
