#include <stdio.h>

int main(void) {
  int A[100], i, n, sw;

  scanf("%d", &n);
  for (i = 0; i < n; i++)  {
    scanf("%d", &A[i]);
  }
  
  sw = bubbleSort(A, n);

  for (i = 0; i < n; i++)  {
    if (i)
      printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", sw);

  return 0; 
}

int bubbleSort(int A[], int n)  {
  int i, j, sw = 0, temp, flag = 1;

  for ( i = 0; flag == 1; i++)  {
    flag = 0;
    for (j = n-1; j >= i+1; j--)  {
      if (A[j] < A[j-1])  {
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp; 
        flag = 1;
        sw++;
      }
    }
  }
  return sw;
}

    
