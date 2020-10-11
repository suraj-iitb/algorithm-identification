#include<stdio.h>
#define  N 100

int SelectionSort(int *B, int n) {
  int i, j, tmp, count = 0, mini;
  
  for(i = 0; i < n; i++) {
    mini = i;
    for(j = i; j < n; j++){
      if(B[j] < B[mini]) mini = j;
      }
    if(B[i] != B[mini]) {
      tmp = B[i];
      B[i] = B[mini];
      B[mini] = tmp;
      count++;
    }
  }
  return count;
}

int main() {
  int i, A[N], n, cnt;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  
  cnt = SelectionSort(A, n);
  
  for(i = 0; i < n; i++) {
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", cnt);
  
  return 0;
}
