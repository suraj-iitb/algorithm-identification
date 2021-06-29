#include<stdio.h>
int main()
{
  int n, q, i, cnt=0;
  int s[100000],t[50000];
  int mid, left, right;
  scanf("%d", &n);
  for(i=0; i<n; i++)
    {
      scanf("%d", &s[i]);
    }
  scanf("%d", &q);
  for(i=0; i<q; i++)
    {
      scanf("%d", &t[i]);
    }
  for(i=0; i<q; i++)
    {
      left = 0;
      right = n;
      while(left < right)
    {
      mid = (left+right)/2;
      if(t[i] == s[mid])
        {
          cnt++;
          break;
        }
      if(t[i] > s[mid])
        {
          left = mid+1;
        }
      else if(t[i] < s[mid])
        {
          right = mid;
        }
    }
    }
 
  printf("%d\n", cnt);
   
  return 0;
}
