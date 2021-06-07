#include <stdio.h>

#define NMAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,time;
int color[NMAX],d[NMAX],f[NMAX];
int M[NMAX][NMAX];

void rec(int i){
  int j;
  color[i] = GRAY;
  d[i] = ++time;
  for(j = 0;j < n;j++){
    if(M[i][j] == 0){
      continue;
    }
    if(color[j] == WHITE){
      rec(j);
    }
  }
  color[i] = BLACK;
  f[i] = ++time;

}
  

int main(void){

  int u,k,v,i,j;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      M[i][j] = 0;
    }
  }

  for(i = 0;i < n;i++){
    scanf("%d%d",&u,&k);
    for(j = 0;j < k;j++){
      scanf("%d",&v);
      M[u - 1][v - 1] = 1;
    }
  }

  for(i = 0;i < n;i++){
    color[i] = WHITE;
  }
  time = 0;

  for(i = 0;i < n;i++){
    if(color[i] == WHITE){
      rec(i);
    }
  }

  for(i = 0;i < n;i++){
      printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
	  
}

