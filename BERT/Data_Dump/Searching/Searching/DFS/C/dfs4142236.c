#include<stdio.h>

int time,n,g[100][100] = {0};
int d[100],f[100],iro[100] = {0};

void dfs(void);
void visit(int);

int main(){
  int i,j,x,y,z;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d %d",&x,&y);
    for(j=0;j<y;j++){
      scanf("%d",&z);
      g[x-1][z-1] = 1;
    }
  }

  dfs();
  return 0;
}

void dfs(){
  int a;

  time = 0;

  for(a=0;a<n;a++)
    if(iro[a] == 0)visit(a);

  for(a=0;a<n;a++)
    printf("%d %d %d\n",a+1,d[a],f[a]);
}

void visit(int x){
  int y;

  iro[x] = 1;
  d[x] = ++time;

  for(y=0;y<n;y++){
    if(g[x][y] == 0)continue;
    if(iro[y] ==0)visit(y);
  }

  iro[x] = 2;
  f[x] = ++time;
}

