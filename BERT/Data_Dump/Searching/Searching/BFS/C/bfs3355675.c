#include<stdio.h>
#define N 101
int n,g[N][N],d[N],q[N],top,tail;

int pop(void){//
int k;
k=q[top];
  if(top==N-1)top=0;
  else top++;
return k;
}

void push(int k){
 if(tail==N-1)tail=0;
 else tail++;
 q[tail-1]=k;
}
void bfs(void){
  int i,j,u,judge[n];
  q[0]=1;
  top=0;
  tail=1;
  d[1]=0;
  for(i=2;i<=n;i++){
    d[i]=-1;
    judge[i]=1;
  }
  
  while(tail!=top){
    u=pop();
    for(i=1;i<=n;i++){
      if(g[u][i]==1&&judge[i]==1){
        judge[i]=0;
        d[i]=d[u]+1;
        push(i);
      }
    }
    judge[u]=-1;
  }
}


int main(){
  int i,j,num,k,r;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      g[i][j]=0;
    }
  }
  for(i=1;i<=n;i++){
    scanf("%d%d",&num,&k);
    for(j=1;j<=k;j++){
        scanf("%d",&r);
        g[i][r]=1;
    }
  }
  bfs();

  for(i=1;i<=n;i++){
  printf("%d %d\n",i,d[i]);
  }
  return 0;
}
