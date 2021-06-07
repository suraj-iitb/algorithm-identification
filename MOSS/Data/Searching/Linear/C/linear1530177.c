#include <stdio.h>

#define SIZE 16384

int linearSearch(int *S, int n, int key){
  int i = 0;
  S[n] = key;
  while (S[i] != key)
    i++;
  if (i == n)
    // not found
    return 0;
  return 1;
}

int main(void){
  int n, q, S[SIZE] = {0}, T[SIZE] = {0}, C = 0, i;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  scanf("%d", &q);
  for (i = 0; i < q; i++)
    scanf("%d", &T[i]);

  // search for S
  for (i = 0; i < q; i++)
    if (linearSearch(S, n, T[i]))
      C++;
  printf("%d\n", C);

  return 0;
}
