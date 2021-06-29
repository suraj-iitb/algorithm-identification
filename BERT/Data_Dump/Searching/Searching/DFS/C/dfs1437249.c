#include<stdio.h>
typedef struct{
  int u;
  int k;
  int v[101];
  int d;
  int f;
  int h;
}Graph;

void dfs(int);
int count=1;
 Graph node[101];
main(){
  int i,j,n;
 
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&node[i].u);
    scanf("%d",&node[i].k);
    node[i].d=0;
    node[i].f=0;
    node[i].h=0;
    for(j=1;j<=node[i].k;j++)scanf("%d",&node[i].v[j]);
  }
  
  for(i=1;i<=n;i++){
    dfs(node[i].u);
  
  }
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",node[i].u,node[i].d,node[i].f);
  }
  return 0;
}


void dfs(int x){
  int i;
  if(node[x].h==0){
    node[x].h=1;
    node[x].d=count;
    count++;
  }
  for(i=1;i<=node[x].k;i++){
    if(node[node[x].v[i]].h==0)dfs(node[x].v[i]);
  }
  if(node[x].h==1){
    node[x].h=2;
    node[x].f=count;
    count++;
  }
}
