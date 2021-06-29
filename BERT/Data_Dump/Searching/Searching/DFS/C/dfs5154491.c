#include <stdio.h>

#define w -3
#define G -2
#define b -1
#define MAX 101

void DFS(void);
void VIS(int);

int n;
int g[MAX][MAX];
int cl[MAX];
int d[MAX];
int f[MAX];
int time;

int main(){
  int i,k,j,ele,num,node;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d%d",&ele,&num);
    for(j=0;j<num;j++){
      scanf("%d",&node);
      g[i][node]=1;
    }
  }

  DFS();

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }

  return 0;
}

void DFS(void){
  int i;
  for(i=1;i<=n;i++){
    cl[i]=w;
  }

  for(i=1;i<=n;i++){
    if(cl[i]==w) VIS(i);
  }
}

void VIS(int u){
  int i;
  cl[u]=G;
  d[u]=++time;
  for(i=1;i<=n;i++){
    if(g[u][i]==1){
      if(cl[i]==w){
	VIS(i);
      }
    }
  }

  cl[u]=b;

  f[u]=++time;
}
