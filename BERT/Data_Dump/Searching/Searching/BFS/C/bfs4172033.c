#include <stdio.h>
#define MAX 101

int A[MAX][MAX], B[MAX], C[MAX];

void serch(int x, int y){
  int i;
  C[x] = y;
  for(i=1; i<=B[x]; i++){
    if(C[A[x][i]] > y)
      serch(A[x][i], y+1);
  }
}

int main(){
  int i,j;
  int a,b;
  
  scanf("%d", &a);
  for(i=1; i<=a; i++){
    C[i] = 10000;
    for(j=1; j<=a; j++)
      A[i][j] = 0;
  }
  
  for(i=1; i<=a; i++){
    scanf("%d", &b);
    scanf("%d", &B[b]);
    for(j=1; j<=B[b]; j++)
      scanf("%d", &A[b][j]);
  }
  
  serch(1,0);
  
  for(i=1; i<=a; i++){
    if(C[i] == 10000)
      C[i] = -1;
    printf("%d %d\n", i, C[i]);
  }
  return 0;
}

