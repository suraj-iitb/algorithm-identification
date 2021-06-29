#include <stdio.h>
#define INF 2147483647

void bfs(int);
void enqueue(int);
int dequeue();

int n,head,tail,Q[100],color[100],d[100],A[100][100];

int main(){
  int i,j,u,k,v;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) A[i][j]=0;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      A[u-1][v-1]=1;
    }
  }
  bfs(0);

  for(i=0;i<n;i++){
    if(d[i]==INF) d[i]=-1;
    printf("%d %d\n",i+1,d[i]);
  }

  return 0;
}

void bfs(int s){
  int i,u;

  for(i=0;i<n;i++){
    color[i]=0;
    d[i]=INF;
  }

  color[s]=1;
  d[s]=0;
  enqueue(s);

  while(head!=tail){
    u=dequeue();

    for(i=0;i<n;i++){
      if(A[u][i]==1&&color[i]==0){
	color[i]=1;
	d[i]=d[u]+1;
	enqueue(i);
      }
    }
    color[u]=2;
  }
}

void enqueue(int x){
  Q[tail]=x;
  if(tail+1==100) tail=0;
  else tail++;
}

int dequeue(){
  int x;

  x=Q[head];
  if(head+1==100) head=0;
  else head++;

  return x;
}
