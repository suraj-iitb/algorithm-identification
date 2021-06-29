#include<stdio.h>
#include<stdlib.h>
#define INF -1
#define N 102
#define white 0
#define gray 1
#define black 2

int q[N],color[N],a[N][N],d[N],n,head=0,tail=0;

void enqueue(int x){
  int next=(tail+1)%N;

  if(head==next){
    printf("Queue overflow!\n");
    exit(2);
  }
  
  q[tail]=x;
  tail=next;
}
int dequeue(void){
  int x;

  if(head==tail){
    printf("Queue is empty!\n");
    exit(3);
  }
  
  x=q[head];
  head=(head+1)%N;
  return x;
}

void bfs(){
  int s=1,i;

  for(i=1;i<=n;i++){
    color[i]=white;
    d[i]=INF;
  }

  color[s]=gray;
  d[s]=0;
  enqueue(s);

  while(head!=tail){
    int u=dequeue();
    for(i=0;i<=n;i++){
      if(a[u][i]&&color[i]==white){
	color[i]=gray;
	d[i]=d[u]+1;
	enqueue(i);
      }
    }
    color[u]=black;
  }
}

void print(){
  int i;
  for(i=1;i<=n;i++) printf("%d %d\n",i,d[i]);
}

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      a[i][j]=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      a[u][v]=1;
    }
  }

  bfs();
  print();

  return 0;
}

