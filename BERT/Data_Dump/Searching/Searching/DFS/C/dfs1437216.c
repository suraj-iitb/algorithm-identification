#include <stdio.h>
typedef struct{
  int a;
  int m;
  int num[100];
  int d;
  int f;
  int c;
} graph;

int count=1;
graph g[101];
void serch(int);

int main(){
  int i,j,n;
  //input
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&g[i].a,&g[i].m);
    g[i].d=g[i].f=g[i].c=0;
    for(j=0;j<g[i].m;j++) scanf("%d",&g[i].num[j]);
  }

  for(i=1;i<=n;i++) serch(g[i].a);

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",g[i].a,g[i].d,g[i].f);
  
  }
  return 0;
}

void serch(int x){
  int i;

  if(g[x].c==0){
    g[x].c++;
    g[x].d=count;
    count++;
  }

  for(i=0;i<g[x].m;i++) if(g[g[x].num[i]].c==0) serch(g[x].num[i]);

  if(g[x].f==0){
    g[x].f=count;
    count++;
  }

}
