# include <stdio.h>

int main(void)  {
  int A[100], n, i, sw;
  
  scanf("%d", &n);
  for (i  = 0; i < n; i++)
    scanf("%d", &A[i]);
  
  sw = selectionSort(A, n);
  
  for (i = 0; i < n; i++)  {
    if (i > 0)
      printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", sw);

  return 0;
}

int selectionSort(int A[], int n)  {
  int i, j, t, sw = 0, minj;
  for (i = 0; i < n - 1; i++)  {
    minj = i;
    for (j = i; j < n; j++)  {
      if (A[j] < A[minj])
        minj = j;
    }
    t = A[i];
    A[i] = A[minj];
    A[minj] = t;
    if (i != minj)
      sw++;
  }
  return sw;
}
