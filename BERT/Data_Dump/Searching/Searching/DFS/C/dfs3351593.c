#include<stdio.h>
#define MAX 100
#define WHILE 0
#define GRAY 1
#define BLACK 2
int G[MAX+1][MAX+1],vt[MAX+1],f[MAX+1];
int col[MAX+1];
int time=0,n;



void visit(int i){
  int u;
  col[i] = GRAY;
  vt[i] = ++time;

  for(u=1; u<=n; u++){
    if(G[i][u] == 0)continue;
    if(col[u] == WHILE){
      visit(u);
    }
  }
  col[i] = BLACK;
  f[i] = ++time;
}


void finish(){
  int i;
  time=0;
  for(i=1; i<=n; i++){
    if(col[i] == WHILE)visit(i);
  }
}

int main(){
  int i,j,l,len,num,k;

  for(i=0; i<MAX+1; i++){
    for(j=0; j<MAX+1; j++){
      G[i][j]=0;
    }
    col[i] = WHILE;
  }
  //表に入れる  
  scanf("%d",&n);
  for(i=1; i<=n; i++){
    scanf("%d %d",&len,&num);
    for(l=0; l<num; l++){
      scanf("%d",&k);
      for(j=1; j<=n; j++){
	if(k==j)G[len][j]=1;
      }
    }
  }

  //探索
  finish();
  
  //出力  
  for(i=1; i<=n; i++){
    printf("%d %d %d\n",i,vt[i],f[i]);
  }
  
  return 0;
}

