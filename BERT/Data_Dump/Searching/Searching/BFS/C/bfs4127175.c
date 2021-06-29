#include<stdio.h>
#include<string.h>
int tansa(int [][101],int,int,int*);
int n;
int main(){
  int i,j,a[101][101],m,l,stack[100],stamp[101][2],now,time=1,depth[101];
  scanf("%d",&n);
  for(i=1;i<=n;i++) for(j=1;j<=n;j++){
      a[i][j]=0;
      depth[j]=-1;
    }
  for(i=1;i<=n;i++){
    scanf("%d %d",&j,&m);

    for(j=1;j<=m;j++){
      scanf("%d",&l);
      a[i][l]=1;
    }
  }
  tansa(a,1,0,depth);
  for(i=1;i<=n;i++){
    printf("%d %d\n",i,depth[i]);
  }
}
int tansa(int a[][101],int now,int nowdep,int* depth){
  int i;
  if(depth[now] > nowdep || depth[now] == -1)
    depth[now]=nowdep;
  for(i=1;i<=n;i++){
    if(a[now][i] == 1 && (depth[i] > nowdep+1 || depth[i] == -1)) tansa(a,i,nowdep+1,depth);
  }
  return 1;
}

