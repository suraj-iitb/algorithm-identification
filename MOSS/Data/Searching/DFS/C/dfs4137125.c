#include<stdio.h>
#define MAX 1000

void DFS(int);

int n;
int time = 1;
int A[MAX][MAX], d[MAX],f[MAX];
int V[MAX];//訪れた場所を記録する配列

int main(){
  int i, j;
  int id, k, R;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d %d", &id, &k);
    for(j = 0; j < k; j++){
      scanf("%d", &R);
      A[id][R] = 1;
    }
  }

  for(i = 1; i <= n; i++){
    DFS(i);
  }
  
  for(i = 1; i <= n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  
  return 0;
}

void DFS(int id){
  int i;

  if(V[id] == 1) return;

  d[id] = time;
  V[id] = 1;
  time++;

  for(i = 1; i <= n; i++){
    if(A[id][i] == 1) DFS(i);
  }

  time++;
  f[id] = time - 1;
}



