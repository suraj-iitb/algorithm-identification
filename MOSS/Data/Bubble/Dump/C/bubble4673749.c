#include <stdio.h>

#include <stdlib.h>


int main() {
 int i, j, k;
 int count;

 int n;
 scanf("%d", &n);

 int A[10000];
 for (i = 0; i != n; i++) {
  scanf("%d", &A[i]);
 }

 for (i = 0; i <n - 1; i++) {
  for (j = 0; j != n - i - 1; j++) {
   if (A[j] >A[j + 1]) {
    //swap
    k =A[j];
   A[j] =A[j + 1];
    A[j + 1] = k;
    count++;
   }
  }
 }
//bubble
 for (i = 0; i <n; i++) {
  if (i == n- 1)printf("%d\n", A[i]);
  else printf("%d ", A[i]);
 }
 printf("%d\n", count);
 return 0;
}

