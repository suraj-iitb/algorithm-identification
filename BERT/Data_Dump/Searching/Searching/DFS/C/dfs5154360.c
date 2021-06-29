#include<stdio.h>
#define MAX 100
int n;
int G[MAX+1][MAX+1];
int d[MAX+1]; //depth
int f[MAX+1]={0};  //finish
int T=0;
void visit(int );


int main(){
  int i,j;
  int u,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++) d[i]=0;
  
  for(i=0;i<n+1;i++){
    for(j=0;j<n+1;j++){
      G[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1]=1;
    }
  }
  for(i=0;i<n;i++){
    if(d[i]==0){
      visit(i);
    }
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

void visit(int u){
  int i,j,v;
  T++;
  d[u]=T; //最初の訪問

  for(v=0;v<n;v++){
    if(G[u][v]==1 && d[v]==0){
      visit(v);
    }
  }
  T++;
  f[u]=T;
}

