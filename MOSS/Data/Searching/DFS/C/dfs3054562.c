#include<stdio.h>
#define MAX 101
int d[MAX];
int color[MAX];
int f[MAX];
int a[MAX][MAX];
int time;
void visit(int,int);
void dfs(int);
int main(){
  int n,i,j,c,r,tmp;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      a[i][j]=0;
    }
  }
  for(j = 1;j<=n;j++){
    scanf("%d %d",&c,&r);
  
    for(i = 1;i<=r;i++){
      scanf("%d",&tmp);
      a[c][tmp] = 1;
    }
  }
 dfs(n);
  for(i = 1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
    }

  
  return 0;
}

void dfs(int n){
  int i;
  for(i =1;i<=n;i++){
    color[i] =0;
  }
  time=0;
  for(i=1;i<=n;i++){
    if(color[i] ==0){
      visit(i,n);
    }
  }
}

void visit(int i,int n){
  int j;
  color[i] = 1;
  d[i] =++time;
  for(j =1;j<=n;j++){
    if(a[i][j] ==1 && color[j] ==0){
      visit(j,n);
    }
  }
  color[i] =2;
  f[i] =++time;
}

