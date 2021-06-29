#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BRACK 2

typedef struct{
  int color;
  int des,fin;
}Roll;

Roll id[N+1];

int si=0,time=1,n;
int G[N+1][N+1],stack[N];

void MakeG(){
  int u,k,i,j,t;
  
  for(i = 1; i <= N; i++){
    for(j = 1; j <= N; j++) G[i][j] = 0;
  }
  
  for(i = 0; i < n; i++){
    scanf("%d%d",&u,&k);
    for(j = 0; j < k; j++){
      scanf("%d",&t);
      G[u][t] = 1;
    }
  }
}

void push(){
  int t;

  t = stack[si];
  id[t].color = BRACK;
  id[t].fin = time;
  time++;
  si--;
}


int pop(int sn){
  id[sn].color = GRAY;
  id[sn].des = time;
  time++;
  si++;
  stack[si] = sn;
  
  for(int i = 1; i <= n; i++){
    if(G[sn][i] == 1 && id[i].color == WHITE){
      sn = i;
      sn = pop(sn);
    }
  }
  push();
  return stack[si];
}

int main()
{
  int i,j,k,u,sn;

  for(i = 0; i < N; i++){
    id[i].color = WHITE;
  }
 
  scanf("%d",&n);
  MakeG();

  sn = 1;

  for(sn = 1; sn <= n; sn++){
    if(id[sn].color == WHITE) pop(sn);
  }

  for(i = 1; i <= n; i++){
    printf("%d %d %d\n", i, id[i].des, id[i].fin);
  }

  return 0;
}

