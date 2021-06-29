#include<stdio.h>

static const int N = 1000;

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void swim(int A[], int begin, int end, int key) {
    int i = 0;
    for(i = end; i >= begin ; i--) {
        if(A[i] <= key) break;
        else A[i+1] = A[i];
    }
    A[i+1] = key;
}

int main(){
  int n;
  int A[N+1];
  scanf("%d", &n);

  for(int i = 0; i < n; i++ ) scanf("%d", &A[i]);

  trace(A, n);
  for(int i = 1; i < n; i++) {
    int key = A[i];
    swim(A, 0, i-1, key);
    trace(A, n);
  }
  return 0;
}
