#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND 100000
int linearSearch(int);
int *S, *T ,n, q;
int main()
{
  int i ,for_count = 0;
  
  scanf("%d",&n);
  S = (int *)malloc((n + 1) * sizeof(int));
  for(i = 0 ; i < n ; i++) scanf("%d",&S[i]);

  scanf("%d",&q);
  T = (int *)malloc(q * sizeof(int));
  for(i = 0 ; i < q ; i++) scanf("%d",&T[i]);

  for(i = 0 ; i < q ; i++){
    if(linearSearch(T[i]) != NOT_FOUND) for_count++; }

  printf("%d\n",for_count);

  free(S);
  free(T);

  return 0;
}

int linearSearch(int key)
{
  int i = 0;
  S[n] =  key;
  while(S[i] != key) i++;
  if(i == n) return NOT_FOUND;
  return i;
}

