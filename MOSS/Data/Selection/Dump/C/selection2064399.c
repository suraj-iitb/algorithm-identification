#include<stdio.h>
int main (void){
  int A[100];
  int n, a, d, i, j, minj;
  a = 0;
  scanf("%d", &n);
  for (i = 0;i < n;i++)
    scanf ("%d", &A[i]);
  for (i = 0;i < n - 1;i++){
    minj = i;
    for (j = i;j < n;j++){
      if (A[j] < A[minj])
        minj = j;
    }
    d = A[i];
    A[i] = A[minj];
    A[minj] = d;
    if (i != minj)
      a++;
  }
  for (i = 0;i < n;i++){
    if (i > 0)
      printf (" ");
    printf ("%d",A[i]);
  }
  printf ("\n");
  printf ("%d\n", a);
  return 0;
 }
