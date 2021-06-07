#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#define ll long long
#define PI acos(-1)
#define ichi 1000000007

int n;
int M[100][100], color[100], time, d[100], f[100], nt[100];

int next (int u) {
  for (int v = nt[u]; v < n; v++) {
    nt[u] = v + 1;
    if (M[u][v]) return v;
  }
  return -1;
}

int stack[100], top;

void pop () {
  top--;
  return ;
}

void push (int x) {
  stack[++top] = x;
  return ;
}

int isempty () {
  return top == 0;
}

void dfs_visit (int u) {
  top = 0;
  for (int i = 0; i < n; i++) nt[i] = 0;
  push(u);
  color[u] = 1;
  d[u] = ++time;
  int t, v;
  while (isempty() != 1) {
    t = stack[top];
    v = next(t);
    if (v != -1) {
      if (color[v] == 0) {
        push(v);
        color[v] = 1;
        d[v] = ++time;
      }
    } else {
      pop();
      color[t] = 2;
      f[t] = ++time;
    }
  }
}

void dfs () {
  time = 0;
  for (int i = 0; i < n; i++) {
    color[i] = 0;
  }
  
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) dfs_visit(i);
  }
}

int main () {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      M[i][j] = 0;
    }
  }
  int u, k, v;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &u, &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &v);
      M[u-1][v-1] = 1;
    }
  }
  
  dfs();
  
  for (int i = 0; i < n; i++) {
    printf("%d %d %d\n", i+1, d[i], f[i]);
  }
  
  return 0;
}
