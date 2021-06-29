#include <stdio.h>
//#include <math.h>
#define MAX 100
#define INFINITY 100000000

int n, M[MAX][MAX], d[MAX], Q[MAX];
int head = 0;
int tail = 0;

void enqueue(int x){
  Q[tail] = x;
  tail = (tail + 1) % MAX;
}
int dequeue(){
  int x = Q[head];
  head = (head + 1) % MAX;
  return x;
}
int isEmpty(void){
  if(head == tail) return 1;
  else return 0;
}
void dfs(int s){
  int i, u, v;
  
  enqueue(s);
  for(i = 0; i < n; i++) d[i] = INFINITY;
  d[s] = 0;
  while( !isEmpty() ){
    u = dequeue();
    for(v = 0; v < n; v++){
      if(M[u][v] == 0) continue;
      if(d[v] != INFINITY) continue;
      d[v] = d[u] + 1;
      enqueue(v);
    }
  }
  for(i = 0; i < n; i++){
    printf("%d %d\n", i + 1, (d[i] == INFINITY ? (-1) : d[i]));
  }
}

int main(){
  int i, j, k, u, v;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++)
      M[i][j] = 0;
  }

  for(i = 0; i < n; i++){
    scanf("%d %d", &u, &k);
    u--;
    for(j = 0; j < k; j++){
      scanf("%d", &v);
      v--;
      M[u][v] = 1;
    }
  }
  
  dfs(0);
  
  return 0;
}

