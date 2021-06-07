#include<stdio.h>
#define N 100
#define step1 1
#define step2 2
#define step3 3

void dfs(void);
void dfs_visit(int);

int M[N][N],n;
int step[N],fvisit[N],lvisit[N],tt;
int main(){

  int i,j,nood,next,num;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&nood, &next);
    nood--;
    for(j=0;j<next;j++){
      scanf("%d",&num);
      num--;
      M[nood][num]=1;
    }
  }

  dfs();
  
  return 0;
}

void dfs(){
  int u;
  
  for(u=0;u<n;u++) step[u]=step1;
  tt=0;

  for(u=0;u<n;u++){
    if(step[u] == step1) dfs_visit(u);
  }

  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,fvisit[u],lvisit[u]);
  }
}

void dfs_visit(int u){
  int v;
  step[u]=step2;
  fvisit[u]=++tt;
  for(v=0;v<n;v++){
    if(M[u][v]==0) continue;
    if(step[v]==step1){
      dfs_visit(v);
    }
  }
  step[u]=step3;
  lvisit[u]=++tt;
}

