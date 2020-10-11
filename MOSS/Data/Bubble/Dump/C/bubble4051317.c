#include<stdio.h>

int sort(int A[], int n){
  int i, g, t;
  int s = 0;
  if (n == 1) {
      s = 0;
      return s;
  }
  for ( i = 0; i < n; i++){
    for ( g = n-1; g >= i+1; g--){
      if ( A[g] < A[g-1] ){
            t = A[g];
            A[g] = A[g-1];
            A[g-1] = t;
            s++;
      }
    }
  }
  return s;
}

int main(){
  int A[100], n, i, s = 0;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  
  s = sort(A, n);

  for ( i = 0; i < n-1; i++ ){
    printf("%d ", A[i]);
  }
  printf("%d", A[i]);
  printf("\n");
  printf("%d\n", s);

  return 0;
}
