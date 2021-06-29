#include<stdio.h>
#include<stdlib.h>
#define INF 100000000

int table[100][100];
int d[100], q_emp = 0, pop_cnt = 0;
int Q[100];

void push(int s){
  Q[q_emp + pop_cnt] = s;
  q_emp++;
}

int pop(){
  int s;
  s = Q[pop_cnt];
  pop_cnt++;
  q_emp--;
  return s;
}

void BFS(int s, int n){
  int i, u, v;
  push(s);
  for(i = 0; i < n; i++) d[i] = INF;
  d[s] = 0;
  while(q_emp != 0){
    u = pop();
    for(v = 0; v < n; v++){
      if(table[u][v] == 0) continue;
      if(d[v] != INF) continue;
      d[v] = d[u] + 1;
      push(v);
    }
  }
  for(i = 0; i < n; i++){
    if(d[i] != INF)
      printf("%d %d\n", i+1, d[i]);
    else
      printf("%d %d\n", i+1, -1);
  }
}


  
  
int main(){
  int i, j, n, u, k, v;
  
  scanf("%d", &n);
  if(n >= 1 && n <= 100){
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++) table[i][j] = 0;
    }
    
    for(i = 0; i < n; i++){
      scanf("%d %d", &u, &k);
      u--;
      for(j = 0; j < k; j++){
	scanf("%d", &v);
	v--;
	table[u][v] = 1;
      }
    }
    
    BFS(0, n);
  }
  return 0;
}

