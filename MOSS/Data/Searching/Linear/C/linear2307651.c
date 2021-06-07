#include <stdio.h>
#define NOT_FOUND -1

int i, j, n, S[100000000], q, T[100000000], N, key, num;
int linearSearch();
int main()
{
  int counter = 0;
  
  scanf("%d", &n); // S???????´???°
  for(i = 0; i < n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", &T[i]);
  
  for(i = 0; i < n; i++)
    {
      num = 0;
      for(j = 0; j < i; j++)
	if(S[j] == S[i]) num++;
      if(num == 0)
	{key = S[i];
	  if(linearSearch() != NOT_FOUND) counter++;
	}
    }
  printf("%d\n", counter);
  
  return 0;
}

int linearSearch()
{
  j = 0;
  T[n] = key;
  while(T[j] != key)
    {
      j++;
    }
  if(j == n) return NOT_FOUND;
  return j;
}
