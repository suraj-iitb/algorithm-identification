#include <stdio.h>

int A[100][100],n,p[100],d[100],f[100],t;

void dfs_v(int i){
  int j;
  p[i]=1;
  t++;
  d[i]=t;

  for(j=0;j<n;j++){
    if(A[i][j]==0) continue;
    if(p[j]==0)dfs_v(j);
  }
  p[i]=2;
  t++;
  f[i]=t;
}

void dfs(){
  int i;
  
  for(i=0;i<n;i++)p[i]=0;
  t=0;

  for(i=0;i<n;i++)if(p[i]==0) dfs_v(i);

  for(i=0;i<n;i++) printf("%d %d %d\n",i+1,d[i],f[i]);
}

int main(){
  int i,j;
  int x,y,z;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&x,&y);
    x--;
    for(j=0;j<y;j++){
      scanf("%d",&z);
      z--;
      A[x][z]=1;
    }
  }

 
  dfs();

  return 0;
}

