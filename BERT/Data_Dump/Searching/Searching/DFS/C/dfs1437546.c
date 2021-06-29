#include <stdio.h>
#define N 102
#define WHITE 0
#define GRAY 1
#define BLACK 2
 
struct info{
  int ver;
  int color;
  int dis_time;
  int fin_time;
} typedef Info;
 
void Dfs(int);
void Visit(int, int);
 
int gin[N][N];
Info x[N];
int vtime = 0;
 
int main(){
  int n, i, j;
 
  scanf("%d", &n);
  for(i = 1; i < n + 1; i++){
    scanf("%d%d", &gin[i][0], &gin[i][1]);
    for(j = 2; j < 2 + gin[i][1]; j++){
      scanf("%d", &gin[i][j]);
    }
  }
  
  Dfs(n);
 
  for(i = 1; i < n + 1; i++){
    printf("%d %d %d\n", gin[i][0], x[i].dis_time, x[i].fin_time);
  }
 
  return 0;
}
 
void Dfs(int n){
  int i, j;
 
  for(i = 1; i < n + 1; i++){
      x[i].ver = gin[i][0];
      x[i].color = WHITE;
      x[i].dis_time = 0;
      x[i].fin_time = 0;
  }
 
  for(i = 1; i < n; i++){
    if (x[i].color == WHITE) Visit(i, n);
  }
   
}
 
void Visit(int k, int n){
  int i;
 
  x[k].color = GRAY;
  x[k].dis_time = ++vtime;
    for(i = 2; i < 2 + gin[k][1]; i++){
     if(x[ gin[k][i] ].color == WHITE) Visit(gin[k][i], n) ;
  }
  x[k].color = BLACK;
  x[k].fin_time = ++vtime;
 
}
