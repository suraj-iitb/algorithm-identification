#include<stdio.h>
#define MAX 100
#define WHITE 1
#define GREY 2
#define BLACK 3
#define NIL -1

int M[MAX][MAX],c[MAX],d[MAX],f[MAX],ts,n;
int queue[MAX],head=0,tail=0;

int deq(){
  head++;
  if(head==MAX){
    head=0;
    return queue[MAX-1];
  }
  return queue[head-1];
}
void enq(int u){
  queue[tail++]=u;
  if(tail==MAX) tail=0;
}

void bfs(){
  int i,u=0;
  for(i=0;i<n;i++){
    c[i]=WHITE;
    d[i]=NIL;
  }
  d[u]=0;
  c[u]=GREY;
  enq(u);

  while(head!=tail){
    u=deq();
    for(i=0;i<n;i++){
      if(M[u][i]==1&&c[i]==WHITE){
	enq(i);
	c[i]=GREY;
	d[i]=d[u]+1;
      }
    }
    c[u]=BLACK;
  }
}

int main(){
  int i,j,u,k,l;
  scanf("%d",&n);

  for(i=0;i<n;i++)
    for(j=0;j<n;j++) M[i][j]=0;

  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&l);
      M[u-1][l-1]=1;
    }
  }
  bfs();
  /*for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(j>0) printf(" ");
      printf("%d",M[i][j]);
    }
    printf("\n");
    }*/
  for(i=0;i<n;i++) printf("%d %d\n",i+1,d[i]);
  return 0;
}

