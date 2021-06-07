#include<stdio.h>
#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF -1

void bfs();
void visit(int);
int dequeue();
void enqueue(int);
int d[101],color[101];
int Q[101],tail=0,head=0,kill,me[101][101];
int main(){
  int baby,i,j,yasuna,sonya;
  scanf("%d",&kill);
  for(i=1;i<=kill;i++)for(j=0;j<=kill;j++)me[i][j]=-1;

  for(i=0;i<kill;i++){
    scanf("%d%d",&yasuna,&sonya);
    for(j=0;j<sonya;j++){
      scanf("%d",&baby);
      me[yasuna][baby]=1;
    }
  }
  bfs();
  for(i=1;i<=kill;i++)printf("%d %d\n",i,d[i]);
}
void bfs(){
  int i,j,k,time=0,u;

  for(i=1;i<=kill;i++){
    color[i]=WHITE;
    d[i]=INF;
  }
  color[1]=GRAY;
  d[1]=0;
  enqueue(1);
  while(tail!=head){
    u=dequeue();
    for(i=1;i<=kill;i++){
      if(me[u][i]!=-1&&color[i]==WHITE){
	color[i]=GRAY;
	d[i]=d[u]+1;
	enqueue(i);
      }
    }
    color[u]=BLACK;
  }
}
void enqueue(int q){
  Q[head]=q;
  head=(head+1)%101;
}
int dequeue(){
  int i=tail;
  tail=(tail+1)%101;
  return Q[i];
}

