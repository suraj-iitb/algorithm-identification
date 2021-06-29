#include <stdio.h>
#include <stdlib.h>
#define N 100
#define WHITE 0
#define BLACK 2
#define GRAY 1

void dfs();
void visit(int);
void push(int);
int pop();
int stackEmpty();
int next(int);

int n;
int time;
int top = -1;
int stack[N];
int color[N];
int d[N];  // find time
int f[N];  // complete time
int m[N][N] = {0};

int main() {
  int i, j;
  int k, u, v;

  // input
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &u);
    scanf("%d", &k);
    for(j = 0; j < k; j++) {
      scanf("%d", &v);
      m[u - 1][v - 1] = 1;
    }
  }

  dfs();

  // output

  for(i = 0; i < n; i++) {
    printf("%d %d %d\n", i+1, d[i], f[i]);
  }

  return 0;
}

void dfs() {
  int i;
  
  for(i = 0; i < n; i++) {
    color[i] = WHITE;
  }
  time = 0;
  for(i = 0; i < n; i++) {
    if(color[i] == WHITE) visit(i);
  }
}

void visit(int r) {
  int u, v;
  static int cnt = 0;

  push(r+1);
  color[r] = GRAY;
  d[r] = ++time;
  while(stackEmpty() != 0) {
    u = stack[top];
    v = next(u);
    if(v != -1) {
      if(color[v-1] == WHITE) {
	push(v);
	color[v-1] = GRAY;
	d[v-1] = ++time;
      } 
    }
    else {
      color[u-1] = BLACK;
      f[u-1] = ++time;
      u = pop();
    }
  }
}

void push(int r) {
  top = top + 1;
  stack[top] = r;
}

int stackEmpty() {
  if(top == -1) return 0;
  else return 1;
}

int pop() {
  if(stackEmpty() == 0){
    printf("error\n");
    exit(4);
  }
  else {
    top = top - 1;
    return stack[top];
  }
}

int next(int u) {
  int i, j;

  // search the next vertex and return it
  for(i = 0; i < n; i++) {
    if((m[u - 1][i] == 1)&&(color[i] == WHITE)) {
      return i+1;
    }
  }
  return -1;
}

