/* include */
#include <stdio.h>

/* define */
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

/* prototype define */
void dfs();
void visit(int);

/* global */
int n, MATRIX[MAX][MAX], COLOR[MAX], GO[MAX], BACK[MAX], stamp;

int main(){
  int from, to, deg, i, j;

  /* input size */
  scanf("%d", &n);

  /* initialize */
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      MATRIX[i][j] =0;
    }
  }
  
  /* create matrix */
  for(i=0;i<n;i++){
    scanf("%d %d", &from, &deg);
    from--;
    for(j=0;j<deg;j++){
      scanf("%d", &to);
      to--;
      MATRIX[from][to] = 1;
    }
  }
  dfs();
  return 0;
}

void dfs() {
  int from;
  
  /* initialize */
  for(from=0;from<n;from++){
    COLOR[from] = WHITE;
  }
  stamp = 0;
  
  /* ??¢?´¢ */
  for(from=0;from<n;from++){
    if(COLOR[from]==WHITE){
      visit(from);
    }
  }
  
  /* print */
  for(from=0;from<n;from++){
    printf("%d %d %d\n", from+1, GO[from], BACK[from]); //from+1: 0????????????????????????
  }
}

void visit(int from){
  int to;
  COLOR[from] = GRAY;
  GO[from] = ++stamp; //??????????¨????
  for(to=0;to<n;to++){
    if(MATRIX[from][to] == 0){ //????????????(?????????)
      continue;
    }
    if(COLOR[to] == WHITE) {
      visit(to); //?????°
    }
  }
  COLOR[from] = BLACK; //?????£???
  BACK[from] = ++stamp; //?¨?????????????
}
