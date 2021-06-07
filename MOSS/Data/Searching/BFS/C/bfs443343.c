/* C Breadth First Search */
#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int time;
int A[101][101]; /* 1<= n <= 100 */
int color[101];
int d[101];
int head=0,tail=0;


void BFS(int s);
void Enqueue(int Q[],int s);
int Dequeue(int Q[]);

int main(){
  int i,j;
  int u,k,v;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      A[i][j]=0;
    }
  }
  

  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      A[u][v]=1;
    }
  }
  
  BFS(1);

  for(i=1;i<=n;i++){
    printf("%d %d\n",i, d[i]);
  }

  return 0;
}

void Enqueue(int Q[],int s){
  Q[tail]=s;
  tail++;
}

int Dequeue(int Q[]){
  head++;
  return Q[head-1];
}

void BFS(int s){
  int i;
  int Q[101];
  int u;

  for(i=1;i<=n;i++){
    color[i]=WHITE;
    d[i]=-1;
  }
  color[s]=GRAY;
  d[s]=0;
  Enqueue(Q,s);
  
  while(head!=tail){
    u=Dequeue(Q);
    for(i=1;i<=n;i++){
      if(A[u][i]==1){   /* check array element */
	if(color[i]==WHITE){
	  color[i]=GRAY;
	  d[i]=d[u]+1;
	  Enqueue(Q,i);
	}
      }
    }
    color[u]=BLACK;
  }
}
