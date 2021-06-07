#include<stdio.h>
#define N 101
#define WH 0
#define BL 1
#define GA 2 

int n,m[N][N];

int a[N],b[N],c[N],t=0;

void tansaku(int u){
  int e;
  a[u] = GA;
  b[u]=++t;
  for(e=1;e<=n;e++){
    if(m[u][e]==1 && a[e]==WH){
      tansaku(e);
    }
  }
  a[u] = BL;
  c[u] = ++t;
}


void depth(){
  int u;
  for(u=1;u<=n;u++){
    a[u]=WH;
    t=0;
  }

  for(u=1;u<=n;u++){
    if(a[u] == WH){
      tansaku(u);
    }
  }

}


int main(){
  int u,i,j,k,l;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      m[i][j] = 0;
    }
  }
  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&l);
      m[i][l] = 1;
    }
  }
  depth();
  for(i=1;i<=n;i++){
    printf("%d %d %d",i,b[i],c[i]);
    printf("\n");
  }
  return 0;
}
