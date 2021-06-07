#include <stdio.h>

int N[101], d[101], f[101], C[101][101], nt[101];
int time, n;

typedef struct stack{
  int arry[101];
  int top;
}Stack;

struct stack S;

int push(int input){
  
  if(S.top < 101){
    S.top++;
    S.arry[S.top] = input;
    return 0;
  } 
  return -1;
}

int pop(){
  if(S.top != 0){
    int temp = S.top;
    S.top--;
    return S.arry[temp];
  }
  else return -1;
}

void init(){
  int i;
  for(i = 0; i < 101; i++){
    S.arry[i] = 0;
  }
  S.top = 0;
}

int next(int u){
  int v;
  for(v = nt[u]; v <= n; v++){
    nt[u] = v + 1;
    if(C[u][v] == 1){
      return v;
    } 
  }
  return -1;
}

void visit(int r){
  for(int i = 0; i < n; i++) nt[i] = 0;

  int u, v;
  push(r);
  N[r] = 1;
  time++;
  d[r] = time;

  while(S.top != 0){
    u = S.arry[S.top];
    v = next(u);

    if(v != -1){
      if(N[v] == 0){
        N[v] = 1;
        time++;
        d[v] = time;
        push(v);
      }
    }
    else
      {
        pop();
        N[u] = 2;
        time++;
        f[u] = time;
      }
  }

}

void dfs(void){
  int i;
  for(i = 0; i < n; i++){ // 0:white 1:gray 2:black
    N[i] = 0;
    nt[i] = 0;
  }
  time = 0;

  for(i = 1; i <= n; i++){
    if(N[i] == 0) visit(i);
  }
}

int main(){
  int  i, j, k, l, q;

  init();

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      C[i][j] = 0;
    }
  }    

  for(i = 1; i <= n; i++){
    scanf("%d%d", &k, &l);
    for(j = 1; j <= l; j++){
      scanf("%d", &q);
      C[k][q] = 1;
    } 
  }

  dfs();
  
  for(i = 1; i <= n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
    
  return 0;
}
    

