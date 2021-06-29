#include <stdio.h>
#define N 100
#define INF 2147483647

typedef struct {
  int s[N];
}queue;

queue Q;

int n, a[N][N];
int head, tail, d[N];


void initialize(){
  head = 0;
  tail = 0;
}

void enqueue(int num){
  if(head == (tail + 1) % N){
    printf("overflow\n");
  }else{
    Q.s[tail] = num;
    if(tail + 1 == N){
      tail = 0;
    }else{
      tail++;
    }
  }
}

int dequeue(){
  int num;
  if(head == tail){
    printf("underflow\n");
    return -1;
  }else{
    num = Q.s[head];
    if(head + 1 == N){
      head = 0;
    }else{
      head++;
    }
    return num;
  }
}

void BFS(int num){
  int i, u, v;
  enqueue(num);
  for(i = 0; i < n; i++){
    d[i] = INF;
  }
  d[num] = 0;
  while(head != tail){
    u = dequeue();
    for(v = 0; v < n; v++){
      if(a[u][v] == 0) continue;
      if(d[v] != INF) continue;
      d[v] = d[u] + 1;
      enqueue(v);
    }
  }
  for(i = 0; i < n; i++){
    printf("%d ", i+1);
    if(d[i] == INF){
      printf("-1\n");
    }else{
      printf("%d\n", d[i]);
    }
  }
}

int main(){
  int i, j, u, k, v;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      a[i][j] = 0;
    }
  }
  
  for(i = 0; i < n; i++){
    scanf("%d%d", &u, &k);
    u--;
    for(j = 0; j < k; j++){
      scanf("%d", &v);
      v--;
      a[u][v] = 1;
    }
  }

  initialize();

  BFS(0);
  
  return 0;
}

