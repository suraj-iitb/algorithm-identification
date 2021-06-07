#include<stdio.h>

int b_search(int *S, int n, int key)
{
  if (n == 0) return 0;
  if (S[n/2] > key) { if(b_search(&S[0], n/2, key)) return 1;}
  else if (S[n/2] < key) { if(b_search(&S[n/2+1], n - n/2, key)) return 1; }
  else return 1;
}

int main()
{
  int n, q, i, C;
  int S[100000+1], T[50000+1];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
    if (b_search(&S[0], n,  T[i])) C++;
  }
  printf("%d\n", C);
  return 0;
}
