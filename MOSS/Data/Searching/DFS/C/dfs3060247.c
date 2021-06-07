#include <stdio.h>
void dfs();
void dfs_visit(int);
#define N 1000
#define W 0
#define G 1
#define B 2


int num,m[N][N];
int color[N],first[N],finish[N],tt;


int main(){
  int tyouten,value,i,j,k;

  scanf("%d",&num);

  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      m[i][j]=0;
    }
  }
  
  for(i=0;i<num;i++){
    scanf("%d %d",&tyouten,&k);
    tyouten--;
    for(j=0;j<k;j++){
      scanf("%d",&value);
      value--;
      m[tyouten][value]=G;
    }
  }
  dfs();

  return 0;

}

void dfs(){
  int u;

  for(u=0;u<num;u++){
    color[u]=W;
  }
  tt=0;
  for(u=0;u<num;u++){
    if(color[u]==W)dfs_visit(u);
  }
  for(u=0;u<num;u++){
    printf("%d %d %d\n",u+1,first[u],finish[u]);
  }
}


void dfs_visit(int a){
  int value;
  color[a]=G;

  first[a]=++tt;
  for(value=0;value<num;value++){
    if(m[a][value]== W)continue;
    if(color[value]==W){
      dfs_visit(value);
    }
  }

  color[a]=B;
  finish[a]=++tt;
}


