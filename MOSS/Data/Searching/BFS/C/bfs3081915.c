#include<stdio.h>

#define N 100
#define INFTY (1<<21)

int n,M[N][N];
int d[N];

void bfs(int s,int len){
  int i;
  len++;
  d[s]=len;
  for(i=0;i<n;i++){
    if(M[s][i]==1){
      if(d[i]<=len&&d[i]>=0)continue;
      bfs(i,len);
    }
  }
}

int main(){
  int i,j,u,k,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&u);
    u--;
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  for(i=0;i<n;i++)d[i]=-1;
    
  bfs(0,-1);

  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,d[i]);
  }

  return 0;
}

