#include <stdio.h>

int LinearSearch(int *X, int n, int key)
{
  int i = 0;
  X[n] = key;
  while(X[i] != key) i++;
  if(i != n) return 1;
  else return 0;
}

int main()
{
  int i, n, S[10000+1], q, T[500], C = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
    if(LinearSearch(S, n, T[i]) == 1) C++;
    else ;
  }

  printf("%d\n",C);
  
  return 0;
}
