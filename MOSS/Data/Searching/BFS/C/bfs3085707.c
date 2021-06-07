#include <stdio.h>

#define N 100
#define inf 1000000000
#define L 1000


int Q[L],head, tail;
int n, mary[N][N], dary[N];

void enqueue(int value){
  Q[tail]=value;
  tail=(tail+1)%L;  
}

void dequeue(){
   head=(head+1)%L; 
}

void bfs(int s){
  int i,u,v;

  enqueue(s);
  for(i=0;i<n;i++)dary[i]=inf;
  dary[s] = 0;
  while(head!=tail){
    u=Q[head];
    dequeue();
    for(v=0;v<n;v++){
      if(mary[u][v]==0)continue;
      if(dary[v]!=inf)continue;
      dary[v]=dary[u]+1;
      enqueue(v);
    }
  }
  for(i=0;i<n;i++){
    printf("%d",i+1);
    if(dary[i]==inf){
      printf(" %d\n",-1);
    }
    else{
      printf(" %d\n",dary[i]);
    }
  }
}
int main(){
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      mary[i][j]=0;
  
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      mary[u][v]=1;
    }
  } 
  bfs(0);
  
  return 0;
}

