#include <stdio.h>
void insertionSort(int *A, int N)
{
  int v, j, i, k;

  for(i = 1; i < N+1; i++){
    for(k = 0; k < N; k++){
      if(k != N-1) printf("%d ", A[k]);
      else printf("%d\n", A[N-1]);
    }
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
  }
}

int main(void)
{
  int a[100], n, i;
  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);

  insertionSort(a, n);

  return 0;
}
