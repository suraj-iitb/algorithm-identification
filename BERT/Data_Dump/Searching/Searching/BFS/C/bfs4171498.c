#include <stdio.h>
#define N 1000
#define INFINITY 1000000

int n,R[N][N];
int col[N],sub[N];
int tail=0,head=0;
int check[N];
void bfs(int);
int main(){
  int s,t,k;
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    check[i]=0;
    for(j=0;j<n;j++){
      R[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d",&s);
    scanf("%d",&t);
    s--;
    for(j=0;j<t;j++){
      scanf("%d",&k);
      k--;
      R[s][k]=1;
    }
  }
  // for(i=0;i<n;i++){
  //for(j=0;j<n;j++){
  // printf("%d ",R[i][j]);
  //}
  //printf("\n");
  //}
  bfs(0);
  return 0;
}
void push(int x){
  sub[tail]=x;
  if(tail+1==N)
    tail = 0;
  else
    tail++;
}
int pop(void){
  int x;
  
  x = sub[head];
  if(head+1==N)
    head=0;
  else
    head++;
  return x;
}
void bfs(int d){
  int u;
  int i,j;
  push(d);
  for(i=0;i<n;i++){
    col[i]=INFINITY;
  }
  col[d]=0;
  while(head!=tail){
    u=pop();
    //check[d]=1;
    /*
    for(i=0;i<n;i++){
      printf("%d %d\n",i+1,col[i]);
    }
    //*/
    for(j=0;j<n;j++){
      if(R[u][j]==0)
	continue;
      if(col[j]!=INFINITY && col[j]<col[u]+1)
	continue;
      if(check[j]==1)
	continue;
      col[j]=col[u]+1;
      push(j);
      check[j]=1;
    }
  }
  for(i=0;i<n;i++){
    printf("%d",i+1);
    printf(" ");
    if(col[i]==INFINITY)
      printf("-1\n");
    else printf("%d\n",col[i]);
  }
}

