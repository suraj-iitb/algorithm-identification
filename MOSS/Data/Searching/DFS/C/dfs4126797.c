//2020.1.23
//s1270188 xxxmk2
//alds1_11b

#include<stdio.h>
#define N 100

//global
int data[N+1][N], num, vi[N+1], t=0, re[N+1][2];

//prototype
void dfs(void);
void visit(int);

int main(){
  int i, j, a, b;

  //input
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d %d",&a,&b);
    for(j=0;j<b;j++) scanf("%d",&data[a][j]);
    data[a][j]=0;
  }

  //dfs
  dfs();
  
  return 0;
}

void dfs(void){
  int u;

  //reset
  for(u=1;u<=num;u++) vi[u]=0;

  for(u=1;u<=num;u++){
    if(vi[u]==0) visit(u);
  }

  for(u=1;u<=num;u++) printf("%d %d %d\n",u,re[u][0],re[u][1]);
}

void visit(int u){
  int v;
  
  vi[u]=1;
  re[u][0]=++t;

  for(v=0;data[u][v]!=0;v++)
    if(vi[data[u][v]]==0) visit(data[u][v]);

  vi[u]=2;
  re[u][1]=++t;
}

