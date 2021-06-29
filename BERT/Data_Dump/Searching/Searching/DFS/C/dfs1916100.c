#include<stdio.h>
#define M 101

int Ad[M][M];
int d[M];
int f[M];
char color[M];
int t;
void visit(int);

int main(){

  int n,i,j,m,u,k;

  scanf("%d",&n);

  for(i=1;i<M;i++){
    for(j=1;j<M;j++){
      Ad[i][j]=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    color[i]='W';
    if(k!=0){for(m=1;m<=k;m++){
      scanf("%d",&Ad[u][m]);
      }
    }
  }
    t = 0;

  for(i=1;i<=n;i++){
    if(color[i]=='W') visit(i);
  }
  
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
 
  return 0;
}

void visit(int u){
  int i=1;

  color[u]='G';
  
  d[u]=++t;

  while(Ad[u][i]!=0){
    if(color[Ad[u][i]]=='W') { visit(Ad[u][i]);}
    i++;
  }
  color[u]='B';
  
  f[u] = ++t;
  
}
