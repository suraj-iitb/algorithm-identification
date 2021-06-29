#include<stdio.h>
#include<stdlib.h>

int binSearch(int*, int, int);

int main()
{
  int i;
  int n, q, C=0;
  int *S, *T;

  scanf("%d", &n);
  S = (int*)malloc(n * sizeof(int));
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
      if(binSearch(S, n, T[i]))C++;
    }

  printf("%d\n", C);

  free(S);
  free(T);
  return 0;
}

int binSearch(int *S, int n, int key)
{
  int left = 0, right = n, mid;

  while(left < right)
    {
      mid = (left + right)/2;
      if(S[mid] == key)return 1;
      else if(key < S[mid])right = mid;
      else left = mid + 1;
    }
  return 0;
}

