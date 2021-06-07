#include<stdio.h>
#include<stdlib.h>

#define N 100

#define white 1
#define gray 0
#define black 2
#define infinity 1000000

void bfs(void);

int M[N][N] = {}, n, color[N];

int main(){
  int i, j, u, k, a;

  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%d%d", &u, &k);
    u--;
    for(j = 0; j < k; j++){
      scanf("%d", &a);
      a--;
      M[u][a] = white;
    }
  }

  bfs();

  return 0;
}

void bfs(){
  int i, j, k, u, que[N], head = 0, tail = 0, d[N];

  for(i = 0; i < N; i++){
    color[i] = white;
    d[i] = infinity;
  }
  
  color[0] = gray;
  d[0] = 0;
  que[tail] = 0;
  tail++;

  while(head != tail){
    if(head == n)
      head = 0;
    
    u = que[head];
    head++;


    for(i = 0; i < n; i++){
      if(M[u][i] == white && color[i] == white){
	color[i] = gray;
	d[i] = d[u] + 1;
	if(tail ==  n)
	  tail = 0;
	que[tail] = i;
	tail++;
	  }
      
      color[u] = black;
    }
  }
  
  for(i = 0; i < n; i++){
    if(d[i] == infinity)
      d[i] = -1;
    printf("%d %d\n", i + 1, d[i]);
  }
  
}

