#include<stdio.h>
#define N 101

void enQ(int);
int deQ(void);
void bfs(int);

int G[N][N]={};
int n,head=0,tail=0,d[N],color[N],Q[N];

int main(){
  int i,j,u,k,v;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1]=1;
    }
  }

  bfs(0);

  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,d[i]);
  }
  return 0;
}
void enQ(int s){
  Q[tail]=s;
  tail++;
  if(tail==N){
    tail=0;
  }
}
int deQ(){
  int num;
  num=Q[head];
  head++;
  if(head==N){
    head=0;
  }
  return num;
}
void bfs(int s){
  int i,u,v;
  for(i=0;i<n;i++){
    color[i]=0;
    d[i]=-1;
  }
  color[s]=1;
  d[s]=0;

  enQ(s);
  while(head != tail){
    u=deQ();
    for(v=0;v<n;v++){
      if(color[v]==0 && G[u][v]==1){
        color[v]=1;
        d[v]=d[u]+1;
        enQ(v);
      }
    }
    color[u]=2;
  }
}
