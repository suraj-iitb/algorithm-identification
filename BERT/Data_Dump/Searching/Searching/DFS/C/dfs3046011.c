#include<stdio.h>
#define N 100
#define W 0
#define Gr 1
#define B 2
int n,t;
int G[N][N],iro[N],D[N],F[N];
void visit(int tar);
void dfs();
int main(){
  int i,j,u,k,in;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<n;j++){
      G[u-1][j]=0;
    }
    if(k!=0){
	for(j=0;j<k;j++){
	  scanf("%d",&in);
	  G[u-1][in-1]=1;
	}
    }
  }
  dfs();
  return 0;
}
void dfs(){
  int i;
  for(i=0;i<n;i++) iro[i] = W;
  t=0;
  for(i=0;i<n;i++){
    if(iro[i]==W) visit(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,D[i],F[i]);
  }
}
void visit(int tar){
  int j;
  iro[tar]=Gr;
  D[tar]=++t;
  for(j=0;j<n;j++){
    if(G[tar][j]==0)continue;
    if(iro[j]==W) visit(j);
  }
  iro[tar]=B;
  F[tar]=++t;
}
