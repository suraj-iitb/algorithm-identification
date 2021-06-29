#include <stdio.h>

int selectionSort(int A[], int N)
{
  int minj = 0, i, j, tmp, count = 0;

  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }

    if(minj != i){      //iとminjが異なり実際に交換が行われた回数
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      count++;
    }
  }
  return count;
}

int main(void)
{
  int i, a[100], n, count = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  count = selectionSort(a, n);

  for(i = 0; i < n - 1; i++){
    printf("%d", a[i]);
    printf(" ");
  }

  printf("%d\n%d\n", a[n-1], count);

  return 0;
}

