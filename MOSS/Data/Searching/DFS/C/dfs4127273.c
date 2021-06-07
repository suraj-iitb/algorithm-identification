#include<stdio.h>
void dfs(void);
void dfs_init(int);
#define N 100
#define origin 0
#define discover 1
#define death 2
int n,X[N][N];
int condition[N],a[N],b[N],c;
int main(){
  int i,j,x,y,z;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	X[i][j]=0;
      }
    }
    for(i=0;i<n;i++){
      scanf("%d %d",&x,&y);
      x--;
      for(j=0;j<y;j++){
	scanf("%d",&z);
	z--;
	X[x][z]=1;
      }
    }
    dfs();
    return 0;		  
}
void dfs(void){
  int x;
  for(x=0;x<n;x++)
    condition[x]=origin;
  c=0;
  for(x=0;x<n;x++){
    if(condition[x]==origin)
      dfs_init(x);
  }
  for(x=0;x<n;x++){
    printf("%d %d %d\n",x+1,a[x],b[x]);
  }
}
void dfs_init(int x){
  int z;
  condition[x]=discover;
  a[x]=++c;
  for(z=0;z<n;z++){
    if(X[x][z]==0)
      continue;
    if(condition[z]==origin)
      dfs_init(z);
    }
  condition[x]=death;
  b[x]=++c;
}

