#include<stdio.h>
#define N 100
#define TRUE 1

typedef struct{
  int id;
  int d;
  int f;
  int flag;
}LIST;

int n,A[N][N],d[N]={0},f[N]={0};;
LIST ans[N]={0};

void DFS(int );

int main(){
  int i,j,l,m,k;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d%d",&l,&k);
    for(j=0;j<k;j++){
      scanf("%d",&m);
      A[l-1][m-1]=TRUE;
    }
  }

  for(i=0;i<n;i++)if(d[i]==0)DFS(i);

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

void DFS(int k){
  int i,j;
  static int t=0;
  if(d[k]!=0)return;
  t++;
  d[k]=t;
  for(i=0;i<n;i++){
    if(A[k][i]==TRUE)DFS(i);
    A[k][i]=0;
  }
  t++;
  f[k]=t;
}
