#include <stdio.h>
#define INF -1
#define W 0
#define G 1
#define B 2
#define N 100000
int n,Q[100],M[100][100];
int color[100],d[100],f[100],tail=0,head=0;

void visit(int);
void bfs(int);
void enqueue(int);
int dequeue();

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }

  bfs(0);

  return 0;
      
}

void bfs(int s){
  int i,u,v;
  for(u=0;u<n;u++){
    color[i] = W;
    d[u] = INF;
  }
  color[s] = G;
  d[s] = 0;
  enqueue(s);

  while (head != tail){
    u = dequeue();
    for(v=0;v<n;v++){
      if(M[u][v]==1){
	if( color[v] == W){
	  color[v] = G;
	  d[v]= d[u] + 1;
	  enqueue(v);
	}
      }
    }
    color[u]=B;
  }
    for(i=0;i<n;i++){
      printf("%d %d\n",i+1,d[i]);
    }
  

}

void enqueue(int x){
  
  Q[tail] = x;
  if(tail+1 == N){
    tail = 0;
  }
  else{
    tail++;
  }
}
 
int dequeue(){
  int x;
  x = Q[head];
  if((head +1) == N){
    head = 0;
  }
  else {
    head++;
  }
  return x;
}

