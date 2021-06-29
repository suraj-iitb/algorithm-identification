#include<stdio.h>

int A[101][101],s[101],d[101],f[101],l;

void dfs(int n){
  int i;
  d[n]=l++;
  for(i=1;i<=s[n];i++){
    if(!d[A[n][i]]) dfs(A[n][i]);
  }
  f[n]=l++;
}

int main(){
  int i,j,b,c,n;
  scanf("%d",&n);
  l=1;
  for(i=1;i<=n;i++){
    d[i]=f[i]=0;
    scanf("%d",&b);
    scanf("%d",&s[b]);
    for(j=1;j<=s[b];j++){
      scanf("%d",&A[b][j]);
    }
  }
  for(i=1;i<=n;i++){
    if(!d[i]) dfs(i);
  }
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}
      

