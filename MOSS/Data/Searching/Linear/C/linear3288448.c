#include<stdio.h>
#include<stdlib.h>

int Search(int*, int, int);

int main()
{
  int i;
  int n, q, C=0;
  int *S, *T;

  scanf("%d", &n);
  S = (int*)malloc((n+1) * sizeof(int));
  if(S == NULL)
    {
      printf("malloc failed\n");exit(1);
    }
  for(i=0;i<n;i++)
    {
      scanf("%d", &S[i]);
    }

  scanf("%d", &q);
  T = (int*)malloc(q * sizeof(int));
  if(T == NULL)
    {
      printf("malloc failed\n");exit(2);
    }
  for(i=0;i<q;i++)
    {
      scanf("%d", &T[i]);
    }

  for(i=0;i<q;i++)
    {
      if(Search(S, n, T[i]))C++;
    }

  printf("%d\n", C);

  free(S);
  free(T);
  return 0;
}

int Search(int *S, int n, int key)
{
  int i=0;
  S[n] = key;
  while(S[i] != key)
    {
      i++;
      if(i==n)return 0;
    }
  return 1;
}

