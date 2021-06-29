#include<stdio.h>
#define MAX 101
#define WH 0
#define GR 1
#define BL 2
void DFSV(int);
void DFS(void);
int G[MAX][MAX];
int D[MAX];
int F[MAX];
int color[MAX];
int n;
int time;
main(){
  int i, j, a, b, v;
  scanf("%d",&n);

  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){

      G[i][j] = 0;

    }
  }

  for(i = 1; i <= n; i++){

    scanf("%d %d", &b, &a);

    for(j = 1; j <= a; j++){

      scanf("%d",&v);

      G[i][v] = 1;
    }
  }
 
  DFS();

  for(i = 1; i <= n; i++)
    {
      printf("%d %d %d\n", i, D[i], F[i]);
    }

 return 0;

}




void DFS(void){
  int i;

  for( i = 1; i <= n; i++ ){

    color[i] = WH;

  }

  time = 0;

 for( i = 1; i <= n; i++ ){
   if( color[i] == WH )
     DFSV(i);

  }

}

void DFSV(int x){
  int j;

  color[x] = GR;

  time++;
 
  D[x] = time;

  for(j = 1; j <= n ; j++){

    if(G[x][j] == 1 && color[j] == WH)
      DFSV(j);
  }
  color[x] = BL;
  F[x] = ++time;
}
