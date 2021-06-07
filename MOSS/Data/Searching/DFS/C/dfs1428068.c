#include<stdio.h>
int a[100][100];
typedef struct{
  int id;
  int d;
  int f;
}Visit;
void AdjMatrix(int, int);
void DFS(int, int);
int a[100][100];
Visit visit[100];
int v=0;
int main(){
  int n, u, k, A, i, j;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      a[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d%d", &u, &k);
    visit[i].id = u;
    visit[i].d = 0;
    visit[i].f = 0;
    for(j  = 0; j < k; j++){
      scanf("%d", &A);
      AdjMatrix(u, A);
    }
  }

  for(i = 0; i < n; i++){
    DFS(i, n);
  }
  
  for(i = 0; i < n; i++){
    printf("%d %d %d\n", visit[i].id, visit[i].d, visit[i].f);
    }
  return 0;
}

void AdjMatrix(int x, int y){
  a[x-1][y-1] = 1;
}

void DFS(int i, int n){
  int j=0;
  if(visit[i].d == 0) {
    v++;
    visit[i].d = v;
  } else return;
  for(j = 0; j < n; j++){
    if(a[i][j] == 1 && visit[j].d == 0) {
      DFS(j, n);
    }
  }
  v++;
  visit[i].f = v;
}
