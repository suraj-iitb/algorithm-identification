#include <stdio.h>
#define NOT_FOUND -1

int linearSearch(int *, int, int);

int main()
{
  int i, j, n, q;
  int count = 0;

  scanf("%d", &n);
  int S[n];
  for(i=0;i<n;i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  int T[q];
  for(i=0;i<q;i++) {
    scanf("%d", &T[i]);
  }

  for(i=0;i<q;i++) {
    if(linearSearch(S, n, T[i])!=NOT_FOUND)
      count ++;
  }
  printf("%d\n", count);

  return 0;
}

int linearSearch(int *A, int n, int key)
{
   int i = 0;
   A[n] = key;
   while (A[i] != key) {
     i++;
   }
   if (i == n)
     return NOT_FOUND;
   return i;
 }

