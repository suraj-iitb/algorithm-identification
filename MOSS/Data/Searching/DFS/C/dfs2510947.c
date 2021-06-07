#include<stdio.h>
#include<stdlib.h>

#define MAX 101

void DFS(int, int);

int Adj[MAX][MAX];
int D[MAX], F[MAX];
int C[MAX]={0};
int count = 1;

int main(void){
  //int Adj[MAX][MAX];
  int i, j, n, u, k, v;

  scanf("%d", &n);
  for(i=1; i<n+1; i++){
    for(j=1; j<n+1; j++){
      Adj[i][j] = 0;
    }
  }

  for(i=1; i<n+1; i++){
    scanf("%d%d", &u, &k);
    for(j=1; j<k+1; j++){
      scanf("%d", &v);
      Adj[i][v] = 1;
    }
  }

  /* A.c
  for(i=1; i<n+1; i++){
    for(j=1; j<n+1; j++){
      if(j == n) printf("%d\n", Adj[i][j]);
      else printf("%d ", Adj[i][j]);
    }
    }*/

  for(i=1; i<n+1; i++){
    if(C[i] == 0) DFS(i, n);
  }

  for(i=1; i<n+1; i++) printf("%d %d %d\n", i, D[i], F[i]);

  return 0;
}

void DFS(int i, int n){
  int j;

  D[i] = count++;
  C[i] = 1;

  for(j=1; j<n+1; j++){
    if(Adj[i][j] == 1 && C[j] == 0) DFS(j, n);
  }

  F[i] = count++;

  return;
}
