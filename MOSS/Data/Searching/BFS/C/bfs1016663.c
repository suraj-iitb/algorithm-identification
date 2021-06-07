#include<stdio.h>
#include<limits.h>
#define MAX 105
#define WHITE 0
#define GRAY 1
#define BLACK 2
void BFS(void);
void Enqueue(int);
int Dequeue(void);
 
int G[MAX][MAX];
int Q[MAX];
int d[MAX];
int f[MAX];
int color[MAX];
int n;
int time;
int s;
int head=0;
int tail=0;
 
int main(){
 
  int i,j,u,k,next;
 
    scanf("%d",&n);
      for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            G[i][j] = 0;
        }
    }
    for(i = 1; i <= n;i++){
        scanf("%d%d",&u,&k);
	if(i == 1)
	  s = u;
        for(j = 1; j <= k; j++){
            scanf("%d",&next);
            G[i][next] = 1;
        }
    }
    BFS();
    for(i = 1; i <= n; i++){
        printf("%d %d\n",i,d[i]);
    }
 
    return 0;
}

void BFS(void){

  int u,v;

  for(u = 1; u <= n; u++){
    color[u] = WHITE;
    d[u] = -1;
  }
  color[s] = GRAY;
  d[s] = 0;
  Enqueue(s);
  while(head != tail){
    u = Dequeue();
    for(v = 1; v <= n; v++){
      if(color[v] == WHITE && G[u][v] == 1){
	color[v] = GRAY;
	d[v] = d[u] + 1;
	Enqueue(v);
      }
    }
    color[u] = BLACK;
  }
}

void Enqueue(int in){

  Q[tail] = in;
  tail++;
}

int Dequeue(void){

  int ans;

  ans = Q[head];
  head++;

  return ans;
}
