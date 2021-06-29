#include <stdio.h>

int main(void)  {
  int n, i, j;
  int A[100];
  
  scanf("%d", &n);
  for (i = 0; i < n; i++)  
    scanf("%d", &A[i]);
  
  trace(A, n);
  insertionSort(A, n);
  
  return 0;
}

void trace(int A[], int n)  {
  int i;
  for (i = 0; i < n; i++)  {
    if ( i > 0) 
      printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void insertionSort(int A[], int n)  {
  int j, i, v;
  for (i = 1; i < n; i++)  {
    v = A[i];
    j = i - 1;
    while ( j >= 0 && A[j] > v)  {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    trace(A, n);
  }
}
