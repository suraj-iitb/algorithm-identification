#include<stdio.h>
#define WHITE 2
#define GRAY 1
#define BLACK 0

int d[101],mat[101][101],m,color[101],Q[101],head=0,tail=0;

void bfs(int s){
  int i,u;
  for(i = 1; i <= m; i++){
    color[i] = WHITE;
    d[i] = -1;
  }
  color[s] = GRAY;
  d[s] = 0;
  Q[tail] = s;
  tail++;
  while(tail != head){
    u = Q[head];
    head++;
    for(i = 1; i <= m; i++){
      if(mat[u][i] == 1 && color[i] == WHITE){
	color[i] = GRAY;
	d[i] = d[u]+1;
	Q[tail] = i;
	tail++;
      }
    }
    color[u] = BLACK;
  }
}


int main(){
  int next[100][100];
  int k,num,i,j;

  scanf("%d",&m);

  for(i = 1; i <= m; i++){
    scanf("%d %d",&num,&k);
    for(j = 1 ; j <= k; j++){
      scanf(" %d",&next[i][j]);
      mat[i][next[i][j]] = 1;
    }
  }

  bfs(1);
  for(i = 1; i <= m; i++){
    printf("%d %d\n",i,d[i]);
    }
}

