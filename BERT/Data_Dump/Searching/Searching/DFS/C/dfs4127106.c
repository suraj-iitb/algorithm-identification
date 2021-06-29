#include <stdio.h>
#include <stdlib.h>

#define MAX 101

int todo[MAX], seen[MAX], adj[MAX][MAX], d[MAX], f[MAX], stack[MAX];
int top=0, Time=1, n;

int pop();
void push(int);
void CreateAdj(int);
void dfs(int);

int main(){
  int a, b, u;
  
  scanf("%d",&n);
  CreateAdj(n);
  for(a = 0; a < n; a++) seen[a] = 0;
  for(a = 0; a < n; a++){
    if(seen[a] == 0) dfs(a+1);
  }
  for(a = 0; a < n; a++){
    printf("%d %d %d\n",a+1,d[a],f[a]);
  }
  return 0;
}

int pop(){
  return stack[top--];
}

void push(int n){
  stack[top++] = n;                                                             
}

void CreateAdj(int n){
  int a, b, u, k, v;
  for(a = 0; a < n; a++){
    for(b = 0; b < n; b++){
      adj[a][b] = 0;
    }
  }
  
  for(a = 0; a < n; a++){
    scanf("%d%d",&u,&k);
    for(b = 0; b < k; b++){
      scanf("%d",&v);
      adj[u-1][v-1] = 1;
    }
  }
}

void dfs(int v){
  int a;
  d[v-1] = Time++;

  seen[v-1] = 1;
  for(a = 0; a < n; a++){
    if(adj[v-1][a] == 1){
      if(seen[a] == 1) continue;
      else dfs(a+1);
    }
  }
  f[v-1] = Time++;
}

