//2020.1.23
//s1270188 xxxmk2
//alds1_11c

#include<stdio.h>
#define N 100

//global
int data[N+1][N], num, vi[N+1];

//prototype
void bfs(int);
void visit(int,int);

int main(){
  int i, j, a, b;

  //input
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d %d",&a,&b);
    for(j=0;j<b;j++) scanf("%d",&data[a][j]);
    data[a][j]=0;
  }

  //bfs
  bfs(1);
  
  return 0;
}

void bfs(int x){
  int i;

  //reset
  for(i=1;i<=num;i++)  vi[i]=-1;

  visit(x,0);
  
  for(i=1;i<=num;i++) printf("%d %d\n",i,vi[i]);
}

void visit(int x,int t){
  int i;
  
  if(vi[x]==-1 || vi[x]>t) vi[x]=t;
  else return;
  for(i=0;data[x][i]!=0;i++) visit(data[x][i],t+1);
}




