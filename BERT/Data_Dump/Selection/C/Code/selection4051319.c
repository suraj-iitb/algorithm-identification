#include<stdio.h>

int selection(int A[], int n){
    int i, mini, t, j, s = 0;
    for ( i = 0; i < n; i++ ){
    mini = i;
    for ( j = i; j < n; j++ ){
      if ( A[j] < A[mini] ) mini = j;
    }
    t = A[i];
    A[i] = A[mini];
    A[mini] = t;
    if ( i != mini ) s++;
  }
  return s;
}

int main(){
  int A[100], n, i, j, t, s = 0, mini;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  
  s = selection(A, n);

  for ( i = 0; i < n - 1; i++ ){
    printf("%d ", A[i]);
  }
  printf("%d", A[i]);
  printf("\n");
  printf("%d\n", s);

  return 0;
}
