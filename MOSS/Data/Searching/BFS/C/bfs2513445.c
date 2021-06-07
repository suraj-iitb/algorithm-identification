#include<stdio.h>
#include<stdlib.h>
 
#define NIL -1
#define MAX 101
 
void BFS(int, int);
void Enqueue(int*,int);
int Dequeue(int*);
 
int Adj[MAX][MAX];
int D[MAX], F[MAX];
int C[MAX]={0};
int count = 1;
int head = 0, tail = 0;
 
int main(void){
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
 
  BFS(1,n);
 
  for(i=1; i<n+1; i++) printf("%d %d\n", i, D[i]);
 
  return 0;
}
 
void BFS(int i, int n){
  int j, u;
 
  for(j=1; j<n+1; j++){
    C[j] = 0;
    D[j] = NIL;
  }
 
  C[i] = 1; D[i] = 0;
  Enqueue(F, i);
 
  while(head != tail){
    u = Dequeue(F);
    for(j=1; j<n+1; j++){
      if(Adj[u][j] == 1){
        if(C[j] == 0){
          C[j] = 2;
          D[j] = D[u]+1;
          Enqueue(F, j);
        }
      }
    }
    C[u] = 1;
  }
 
  return;
}
 
void Enqueue(int *F, int i){
 
  F[tail]=i;
  tail++;
 
  return;
}
 
int Dequeue(int *F){
 
  head++;
  return F[head-1];
}
