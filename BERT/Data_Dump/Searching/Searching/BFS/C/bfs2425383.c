#include <stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
void bfs(void);

void enqueue(int);
int dequeue(void);
int G[N][N],d[N],f[N],n,Q[N],tail,head,color[N],time;
int main(){

  int i,j,y,b,k;

  for(i=1;i<=100;i++){
    for(j=1;j<=100;j++){
      G[i][j]=0;
    }
  }
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d%d",&y,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&b);
      G[y][b]=1;
      
    }
  }

  bfs();

  for(i=1;i<=n;i++){
    if(d[i]==2000000)
      d[i]=-1;
    printf("%d %d\n",i,d[i]);
  }
  return 0;
}

void bfs(){
  int i,u;
  for(i=1;i<=n;i++){
    color[i]=WHITE;
    d[i]=2000000;
  }
  color[1]=GRAY;
  d[1]=0;
  
  enqueue(1);

  while(head!=tail){
    u=dequeue();
    for(i=1;i<=n;i++){
      if(G[u][i]!=0){
      if(color[i]==WHITE){
	color[i]=GRAY;
	d[i]=d[u]+1;
	enqueue(i);
      }}
    }
    color[u]=BLACK;
   
  }
}

void enqueue(int x){
  
  Q[tail]=x;
  if(tail+1==N)
    tail=0;
  else
    tail++;
}

int dequeue(){
  int x;
  x=Q[head];
  if(head+1==N){
    head=0;
  }
  else
    head++;
  return x;
}
 
