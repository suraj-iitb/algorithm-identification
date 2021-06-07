#include<stdio.h>

#define WHITE 0
#define GRAY 1;
#define BLACK 2;
#define INF -1;

void enq(int);
int deq(void);
void bfs(int);

int a[100][100];
int color[100];
int d[100];
int n;
int Q[200];
int head=0,tail=0;

int main(){
  int u,i,j,k,v;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j] = 0;
    }
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      a[u-1][v-1] = 1;
    }
  }
  
  bfs(0);

  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,d[i]);
  }
  return 0;
}

void enq(int s){
  Q[tail++] = s;
}

int deq(){
  return Q[head++];
}

void bfs(int s){
  int i,j,u;
  
  for(i=0;i<n;i++){
    color[i] = WHITE;
    d[i] = INF;
  }
  color[s] = GRAY;
  d[s] = 0;
  enq(s);


  while(head != tail){
    u = deq();
    for(i=0;i<n;i++){
      if(a[u][i] == 1){
	if(color[i] == WHITE){
	  color[i] = GRAY;
	  d[i] = d[u] + 1;
	  enq(i);
	}
      }
    }
    color[u] = BLACK;
  }
}
