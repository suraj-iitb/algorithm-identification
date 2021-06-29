#include <stdio.h>

int main(void)
{
 int N;
 int i, j, k;
 int v;

 scanf("%d", &N);

 int A[N];
 
 for (i = 1; i < N; i++){
  scanf("%d", &A[i-1]);
  printf("%d ", A[i-1]);
  }
  scanf("%d", &A[N-1]);
  printf("%d\n", A[N-1]);

 for (i = 1; i < N; i++){
  v = A[i];
  j = i -1;
  while (j >= 0 && A[j] > v){
   A[j+1] = A[j];
   j = j--;
   }
  A[j+1] = v;
 
  for (k = 1; k < N; k++){
   printf("%d ", A[k-1]);
   }
  printf("%d\n", A[N-1]);

  }

 return 0;
 
}
