#include<stdio.h>
#define N 101
#define WHITE -1
#define GRAY 0
#define BRACK 1
#define INF -1

int G[N][N] = {}, d[N] = {}, color[N], Q[N];
int n, head = 1, tail = 1;

void Enqueue(int);
int Dequeue(void);
void BFS(int);

int main(){
  int u, k, v, i, j;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d%d", &u, &k);
    for(j = 0; j < k; j++){
      scanf("%d", &v);
      G[u][v] = 1;
    }
  }
  BFS(1);
  for(i = 1; i <= n; i++){
    printf("%d %d\n", i, d[i]);
  }
  return 0;
}

void BFS(int s){
  int i, u;
  for(i = 1; i <= n; i++){
    color[i] = WHITE;
    d[i] = INF;
  }
  color[s] = GRAY;
  d[s] = 0;
  for(i = 1; i <= n; i++) Q[i] = 0;
  Enqueue(s);
  while(head != tail){
    u = Dequeue();
    for(i = 1; i <= n; i++){
      if(G[u][i] == 1){
	if(color[i] == WHITE){
	  color[i] = GRAY;
	  d[i] = d[u] + 1;
	  Enqueue(i);
	}
      }
    }
    color[u] = BRACK;
  }
}

int Dequeue(void){
  int x;
  x = Q[head];
  if(head + 1 == n) head = 1;
  else head++;
  return x;
}

void Enqueue(int x){
   Q[tail] = x;
  if(tail + 1 == n) tail = 1;
  else tail++;
}
