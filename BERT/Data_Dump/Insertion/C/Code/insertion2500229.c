
#include<stdio.h>

static const int N = 1000;

void trace(int A[], int n){
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){
  int n, i, j;
  int A[N+1];
  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);
  
  trace(A, n);

for (i = 2; i <= n; i++)
{
     int t = A[i];
     int x = i - 1;
     while(x > 0 && A[x] > t)
     {
          A[x + 1] = A[x];
          x--;
     }
     A[x + 1] = t;
     trace(A, n);
}


  return 0;
}
