#include<stdio.h>
#define N 501
int n,M[N][N];
int t=0,A[N],B[N],C[N];
//黒が２、グレーが１、白が０
void dfs(int);

int main(){
  int a,b,c;
  int i,j;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      M[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d %d", &a, &b);
    a--;
    for(j = 0; j < b; j++){
      scanf("%d", &c);
      c--;
      M[a][c] = 1;
    }
  }

  for(i = 0; i < n; i++)
    A[i] = 0;

  for(i = 0; i < n; i++){
    if( A[i] == 0)
      dfs(i);
  }

  for( i = 0; i < n; i++)
    printf("%d %d %d\n", i+1, B[i], C[i]);

  return 0;
}

void dfs(int i){
  int j;
  A[i] = 1;
  t++;
  B[i] = t;
  for( j = 0; j < n; j++){
    if( M[i][j] == 0)
      continue;
    if( A[j] == 0)
      dfs(j);
  }
  A[i] = 2;
  C[i] = ++t;
}


