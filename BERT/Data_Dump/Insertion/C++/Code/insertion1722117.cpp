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
  int n, i, j, key, l, m;
  int A[N+1];
  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);
  
  //trace(A, n);
  for ( l=1;l<=n;l++) {
    key=A[l];
    m = l-1;
    while(m>=0 and A[m]>key) {
        A[m+1] = A[m];
        m--;
    }
    A[m+1]=key;
    trace(A, n);  
  }
  
  return 0;
}
