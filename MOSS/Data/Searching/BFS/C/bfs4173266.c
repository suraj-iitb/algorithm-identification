#include <stdio.h>

#define N 100
#define INFTY (1<<21)
#define white 0
#define gray 1
#define black 2
int enq(int);
int deq(void);
void bfs(int);

int n,M[N][N],d[N],Q[N],head,tail;

int main(){
  int u,k,v,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  bfs(0);
  
  return 0;
}
void bfs(int s){
    int i,v,u;
    char color[N];
  for(i=0;i<n;i++){
      color[i]=white;
      d[i]=INFTY;
  }
  color[s]=gray;
  d[s]=0;
  enq(s);
  while(1){
      if(head==tail)break;
      u=deq();
      for(v=0;v<n;v++){
          if(M[u][v]&&color[v]==white){
              color[v]=gray;
              d[v]=d[u]+1;
              enq(v);
          }
      }
      color[u]=black;
  }
for(i=0;i<n;i++){
    printf("%d ",i+1);
    if(d[i]==INFTY)printf("-1");
    else printf("%d",d[i]);
    printf("\n");
}
}
int enq(int x){
  
  Q[tail]=x;
  tail=(tail+1)%N;
  return x;
}
int deq(){
  int x;
  
  x=Q[head];
  head=(head+1)%N;
  return x;
}

