#include <stdio.h>

int A[100][100];
int Color[100];
int d[100],f[100];
int n,time1=0;

void vist(int u){
  int v;
  Color[u]=1;
  d[u]=++time1;
  for(v=0;v<n;v++){
    if(A[u][v]==1 && Color[v]==0) vist(v);
  }
  f[u]=++time1;
}

int main() {
  int i,u,j,k;
  int v;

  for(i=0;i<100;i++) Color[i]=0;

  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      A[i][j]=0;
    }
  }

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u=u-1;
    if(k!=0){
      for(j=0;j<k;j++){
        scanf("%d",&v);
        v=v-1;
        A[u][v]=1;
      }
    }
  }

  for(i=0;i<n;i++){
    if(Color[i]==0) vist(i);
  }
  for (i=0; i<n;i++) {
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}
