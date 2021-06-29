#include<stdio.h>
void bfs();
void enqueue(int);
int dequeue();
int n,a[100][100],d[100],Q[100],tail=0,head=0,q=1;
int main(){
  int u,k,v,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++)for(j=0;j<n;j++)a[i][j]=0;
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      a[u][v]=1;
    }
  }
  bfs();
  for(i=0;i<n;i++)printf("%d %d\n",i+1,d[i]);
  return 0;
}
void bfs(){
  int i,u;
  for(i=0;i<n;i++){

    d[i]=-1;
  }

  d[0]=0;
  enqueue(0);
  while(q){
    u=dequeue();
    for(i=0;i<n;i++){
      if(a[u][i]==0)continue;
      if(d[i]!=-1)continue;
        d[i]=d[u]+1;
        enqueue(i);
    }

  }
}
void enqueue(int s){
  int next=(tail+1)%100;
  Q[tail]=s;
  tail=next;
}
int dequeue(){
  int val;
  if(head==tail)q=0;
  val=Q[head];
  head=(head+1)%100;

  return val;
}
