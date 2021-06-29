#include<stdio.h>
#include<stdlib.h>
#define INF 100000000

int route[100][100];
int d[100], qe = 0, pc = 0;
int q[100];

void push(int);
int pop(void);
void bfs(int, int);

int main(){
  int i, j, n, u, k, v;

  scanf("%d", &n);
  if(n >= 1 && n <= 100){
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++) route[i][j] = 0;
    }

    for(i = 0; i < n; i++){
      scanf("%d %d", &u, &k);
      u--;
      for(j = 0; j < k; j++){
	scanf("%d", &v);
	v--;
	route[u][v] = 1;
      }
    }

    bfs(0, n);
  }
  return 0;
}

void push(int s){
  q[qe + pc] = s;
  qe++;
}

int pop(){
  int s;
  s = q[pc];
  pc++;
  qe--;
  return s;
}

void bfs(int s, int n){
  int i, u, v;
  push(s);
  for(i = 0; i < n; i++) d[i] = INF;
  d[s] = 0;
  while(qe != 0){
    u = pop();
    for(v = 0; v < n; v++){
      if(route[u][v] == 0) continue;
      if(d[v] != INF) continue;
      d[v] = d[u] + 1;
      push(v);
    }
  }
  for(i = 0; i < n; i++){
    if(d[i] != INF){
      printf("%d %d\n", i+1, d[i]);
    }else{
      printf("%d %d\n", i+1, -1);
    }
  }
}

