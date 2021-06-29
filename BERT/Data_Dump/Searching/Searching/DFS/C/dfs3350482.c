#include<stdio.h>

#define N 100

void funk(int);

int graph[N][N],A[N],B[N];
int x,time = 0;

int main() {
  int i,j,a,b,c;

  scanf("%d",&x);
  for(i = 0; i < x; i++) {
    scanf("%d%d",&a,&b);
    for(j = 0; j < b; j++) {
      scanf("%d",&c);
      graph[a - 1][c - 1] = 1;
    }
  }

  for(i = 0; i < x; i++) {
    if(A[i] == 0) {
      funk(i);
    }
  }

    for(i = 0; i < x; i++) {
      printf("%d %d %d\n", i + 1, A[i], B[i]);
    }

    return 0;
}

void funk(int a) {
  int n;
  time++;
  A[a] = time;

  for(n = 0; n < x; n++) {
    if(graph[a][n] != 0 && A[n] == 0) {
      funk(n);
    }
  }

  time++;
  B[a] = time;
}
			

  

