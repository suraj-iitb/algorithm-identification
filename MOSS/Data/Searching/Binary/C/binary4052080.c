#include<stdio.h>

#define MAX 1000000000

int n;
int s[MAX];
int linearSearch(int);

int main()
{
  int i, q, count = 0;
  int t;

  scanf("%d", &n);
  for( i = 0; i < n; i++)
    {
      scanf("%d", &s[i]);
    }
  
  scanf("%d", &q);
  for( i = 0; i < q; i++)
    {
      scanf("%d", &t);
      count += linearSearch(t);
    }
  printf("%d\n", count);

  return 0;
}
  
int linearSearch(int key)
{
  int left = 0;
  int right = n;
  int mid;

  while(left < right)
    {
      mid = (left + right) / 2;
      if(s[mid] == key)return 1;
      else if(key < s[mid])right = mid;
      else left = mid + 1;
    }
  return 0;
}

