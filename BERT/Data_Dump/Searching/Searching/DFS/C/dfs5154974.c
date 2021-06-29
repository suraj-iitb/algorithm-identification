#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
int find[MAX];
int finish[MAX];
/*0 white, 1 gray, 2 black*/
int flag[MAX];
int v[MAX][MAX];
int time;

int visit(int u, int n){
  int i, j;

  flag[u] = 1;
  find[u] = ++time;

  for(i = 0; i < n; i++){
    if(v[u][i] == 1 && flag[i] == 0){
      visit(i, n);
    }
  }

  flag[u] = 2;
  finish[u] = ++time;
}

int dfs(int u, int n){
  int i, j;

  for(i = 0; i < n; i++){
    flag[i] = 0;
  }

  time = 0;

  for(i = 0; i < n; i++){
    if(flag[i] == 0){
      visit(i, n);
    }
  }
}

int main(){
  int a, b, i, j, u, k, l, m, n;
  a = b = i = j = u = k = l = m = n = 0;
  scanf("%d", &n);
  int w[MAX];

  /*初期化*/
  for(i = 0; i < n; i++){
    w[i] = 0;
    for(j = 0; j < n; j++){
      v[i][j] = 0;
    }
  }

 /*in*/
  i = j = l = 0;
  for(i = 0; i < n; i++){
    scanf("%d %d", &u, &k);
    for(j = 0; j < k; j++){
      scanf("%d", &w[j]);
    }

    a = u - 1; 
    if(k >= 1){
      for(l = 0; l < k; l++){
        b = w[l] - 1;
        v[a][b] = 1;
      }
     }
    u = k = a = 0;
  }
  i = 0;

  /*探索*/
  for(i = 0; i < n; i++){
      dfs(i, n);
  }
  for(i = 0; i < n; i++){
      printf("%d %d %d\n", i+1, find[i], finish[i]);
  }
  return 0;
}
