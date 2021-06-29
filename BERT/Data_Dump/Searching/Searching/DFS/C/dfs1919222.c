#include <stdio.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BRACK 2

void visit(int);

int array[MAX][MAX], road_color[MAX] ,arr1[MAX], arr2[MAX];
int n, vst=0;

int main(){
  int num1, num2, num3, i, j;

  scanf("%d", &n);

  for( i=0; i<n; i++){
    for( j=0; j<n; j++){
      array[i][j] = 0;
    }
  }

  for( i=0; i<n; i++){
    scanf("%d %d", &num1, &num2);
    num1--;

    for( j=0; j<num2; j++){
      scanf("%d", &num3);
      num3--;

      array[num1][num3] = 1;
    }
  }

  for( i=0; i<n; i++){
    road_color[i] = WHITE;
  }

  for( i=0; i<n; i++){
    if( road_color[i] == WHITE )visit(i);
  }

  for( i=0; i<n; i++){
    printf("%d %d %d\n", i+1, arr1[i], arr2[i]);
  }

  return 0;
}

void visit(int u ){
  int i;

  road_color[u] = GRAY;

  arr1[u] = ++vst;

  for( i=0; i<n; i++){
    if( array[u][i] == 0 )continue;

    if( road_color[i] == WHITE )visit(i);
  
  }
    road_color[i] = BRACK;

    arr2[u] = ++vst;
}
