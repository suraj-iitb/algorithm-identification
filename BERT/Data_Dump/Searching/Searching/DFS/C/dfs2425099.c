#include <stdio.h>

#define WHITE 1
#define BLACK 0
#define GRAY -1
#define N 250

void dfs(void);
void visit(int);

int d[N];
int f[N];
int color[N];
int str[N][N];
int count = 0;
int n;

int main(){

 int i;
 int j;
 int k;
 int num;
 int point;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
  scanf("%d%d",&num,&k);
  for(j=1;j<=k;j++){
  scanf("%d",&point);
  str[i][point] = 1;
    }
   }

   dfs();
  
  for(i=1;i<=n;i++){
  printf("%d %d %d\n",i,d[i],f[i]);
   }   

  return 0;
}

void dfs(void){

  int u;
  
  for(u=1;u<=n;u++){
    color[u] = WHITE;
  }

  for(u=1;u<=n;u++){
    if(color[u]==WHITE){
      visit(u);
    }
  }
}

void visit(int u){

  int v;

  color[u] = GRAY;
  d[u] = ++count;

  for(v=1;v<=n;v++){
    if(color[v]==WHITE && str[u][v]==1){
      visit(v);
    }
  }

  color[u] = BLACK;
  f[u] = ++count;

}
  
