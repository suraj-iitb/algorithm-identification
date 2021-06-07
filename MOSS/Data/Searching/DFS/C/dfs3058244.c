#include <stdio.h>

int D[101];
int co[101];
int F[101];
int A[101][101];
int time;
void tp(int,int);
void dfs(int);
int main(){
  int i,n,j,c,r,temp;
    //値の入力
  scanf("%d",&n);
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){   
	A[i][j]=0;
      }
    }
    for(j=1;j<=n;j++){  
      scanf("%d%d",&c,&r);

      for(i=1;i<=r;i++){
	scanf("%d",&temp);
	A[c][temp]=1;
      }
    }

    dfs(n);
    
    for(i=1;i<=n;i++){
      printf("%d %d %d\n",i,D[i],F[i]);
    }

    return 0;

}

void tp(int i,int n){
  int j;
  co[i]=1;
  D[i]=++time;
  for(j=1;j<=n;j++){

    if(A[i][j]==1 && co[j]==0)tp(j,n);
  
  }
  co[i]=2;
  F[i]=++time;

}
void dfs(int n){
  int i;
  for(i=1;i<=n;i++){
    co[i]=0;
  }
  time=0;
  for(i=1;i<=n;i++){
    if(co[i]==0) tp(i,n);
  }
}

