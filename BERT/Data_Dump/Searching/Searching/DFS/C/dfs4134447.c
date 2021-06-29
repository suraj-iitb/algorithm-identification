#include <stdio.h>
#include <stdlib.h>
#define N 100
#define W 0
#define G 1
#define B 2

int *data[N],d[N],f[N],t=0;

void seach(int ,int *,int *);

int main(){
  int n,i,j,p,q[N],color[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&p);
    color[p]=W;
      scanf("%d",&q[p]);
    data[p]=(int *)malloc(q[p]*sizeof(int));
    for(j=0;j<q[p];j++){
      scanf("%d",&data[p][j]);
    }
  }

  for(i=1;i<=n;i++){
    if(color[i]==W){
      seach(i,q,color);
    }
  }

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}


void seach(int x,int *q,int *color){
  int i;

  color[x]=G;
  t++;
  d[x]=t;

  for(i=0;i<q[x];i++){
    if(color[data[x][i]]==W){
      seach(data[x][i],q,color);
    }
  }
  color[x]=B;
  t++;
    f[x]=t;
  }

