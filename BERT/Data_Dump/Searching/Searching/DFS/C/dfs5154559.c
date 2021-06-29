#include<stdio.h>

#define WHITE 1
#define BLACK 2
#define GRAY  3
#define MAX 101

typedef struct {
  int k;
  int v[MAX];
} node;

node N[MAX];

int color[MAX], d[MAX], f[MAX];
int n, time;

void visit(int u){
  int i;
  
  color[u] = GRAY;  // 1回通りましたよ
  time++;
  d[u] = time;

  for(i = 1; i <= N[u].k; i++){
    if(color[N[u].v[i]] == WHITE) visit(N[u].v[i]);
  }
  color[u] = BLACK;  // 2回通りましたわよ
  time++;
  f[u] = time;
}

void DFS(){
  int i;
  for(i = 1; i <= n; i++) color[i] = WHITE;
  time = 0;
  for(i = 1; i <= n; i++){
    if(color[i] == WHITE) visit(i);
  }
}

int main(){
  int i, j, u, k, v;

  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    scanf("%d", &u);
    scanf("%d", &N[u].k);
    
    for(j = 1; j <= N[u].k; j++){
      scanf("%d", &N[u].v[j]);
    }
  }
  DFS();
  for(i = 1; i <= n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  return 0;
}

