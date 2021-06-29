#include<stdio.h>
#define N 100
#define NEVER 0
#define FIRST 1
#define SEC 2
int n,A[N][N];
int tr[N],de[N],fi[N],times;

void visit(int u){
  int i;
  tr[u]=FIRST;
  de[u]=++times;
  for(i=0;i<n;i++){
    if(A[u][i]==0)continue;
    if(tr[i]==NEVER){
      visit(i);
    }
  }
  tr[u]=SEC;
  fi[u]=++times;
}

void DeFiSe(){
  int j;
  for(j=0;j<n;j++)tr[j]=NEVER;
  times=0;

  for(j=0;j<n;j++){
    if(tr[j]==NEVER)visit(j);
  }
  for(j=0;j<n;j++){
    printf("%d %d %d\n",j+1,de[j],fi[j]);
  }
}

int main(){
  int i,j,c,d,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)A[i][j]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&c,&d);
    c--;
    for(j=0;j<d;j++){
      scanf("%d",&k);
      k--;
      A[c][k]=1;
    }
  }
  DeFiSe();
  return 0;
}

