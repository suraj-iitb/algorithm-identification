//Depth First Serch
//2019-01-25
//Ebitani Akira

#include <stdio.h>
#include <stdlib.h>

#define N 100
#define AN 128

void DepthSerch(void);
void DepthVisit(int);

int array[AN][AN];
int visit[AN];
int times = 0;
int D[AN], F[AN];
int n;

int main (){
  int i, j;
  int u, k, v;

  scanf("%d", &n);
  if(n > N || n < 1){
    printf("頂点の数が適当ではありません。\n");
    exit(1);
  }

  for(i = 0 ; i < n ; i++){
    for(j = 0 ; j < n ; j++){
      array[i][j] = 0;
    }
  }
  
  for(i = 0 ; i < n ; i++){
    scanf("%d%d", &u, &k);
    u = u-1;
    for(j = 0 ; j < k ; j++){
      scanf("%d", &v);
      v = v-1;
      array[u][v] = 1;
    }
  }

  DepthSerch();

  return 0;
}

void DepthSerch(void){
  int i;

  for(i = 0 ; i < n ;i++){
    visit[i] = 0;
  }

  for(i = 0 ; i < n ;i++){
    if(visit[i] == 0)
      DepthVisit(i);
  }
  for(i = 1 ; i <= n ;i++){
    printf("%d %d %d\n", i, D[i-1], F[i-1]);
  }
}

void DepthVisit(int a){
  int v;
  
  visit[a] = 1;
  D[a] = ++times;
  
  for(v = 0 ; v < n ; v++){
    if(array[a][v] == 0) continue;
    if(visit[v] == 0){
      DepthVisit(v);
    }
  }
  visit[a] = 2;
  F[a] = ++times;
}

