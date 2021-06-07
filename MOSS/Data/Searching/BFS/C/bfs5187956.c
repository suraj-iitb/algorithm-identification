#include<stdio.h>
#define LEN 100005
typedef struct pp{
  char name[100];
  int t;
}P;
P Q[LEN+1];
int head=0, tail=0,a[101][101],d[101];
int Empty(){
  if(head == tail) return 1;
  return 0;
}
void enqueue(int x){
  Q[tail].t = x;
  tail = (tail+1)%100005;
}

int dequeue(){
  int x;
  x = Q[head].t;
    if(head + 1 == 100005)
      head = 0;
    else{
      head = (head+1)%100005;
    }
  return x;
}
void bfs(int n){
  int i,u,v,color[n+1];
  for(u=1;u<=n;u++)
    {
      color[u] =0;
      d[u] = -1;
    }
  color[1] = 1;
  d[1] = 0;
  enqueue(1);
  while(Empty() != 1){
    u = dequeue();
    for(v=1;v<=n;v++){
      if(color[v] == 0 && a[u][v] ==1){
	color[v]  = 1;
	d[v] = d[u] + 1;
	enqueue(v);
      }
    }
    color[u] = 2;
  }
  for(i=1;i<=n;i++) printf("%d %d\n",i,d[i]);
    }

int main(){
   int n,i,j,k,v,id;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&id,&k);
     for(j=1;j<=n;j++) a[i][j] = 0;
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      a[id][v] =1; 
  }
  }
   bfs(n);
  return 0;
}

