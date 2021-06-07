#include<stdio.h>
#define WHITE 1
#define BLACK 2
#define GRAY 3
#define INFTY -1

int Q[100];
int head=0,tail=0;
int color[100],d[100];
int M[100][100];
int n;

void bfs(int);
void enqueue(int);
int dequeue(void);

int main(){
  int i,j,u,v,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    if(k!=0){
      for(j=1;j<=k;j++){
	scanf("%d",&v);
	v--;
	M[u][v]=1;
      }
    }
  }

  bfs(0);

  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,d[i]);
  }
  
  return 0;

}  

void enqueue(int x){
  Q[tail]=x;
  tail++;
}

int dequeue(){
  int y=Q[head];
  head++;
  return y;
}


void bfs(int s){
  int i,u,v;
  for(i=0;i<n;i++){
    color[i]=WHITE;
    d[i]=INFTY;
  }
  color[s]=GRAY;
  d[s]=0;
  enqueue(s);
  while(head!=tail){
    u=dequeue();
    for(v=0;v<n;v++){
      if(M[u][v]==1&&color[v]==WHITE){
	color[v]=GRAY;
	d[v]=d[u]+1;
	enqueue(v);{
	  if(M[u][v]==1&&color[v]==WHITE){
	    color[v]=GRAY;
	    d[v]=d[u]+1;
	    enqueue(v);
	  }
	}
      }
    }
    color[u]=BLACK;
  }
}

