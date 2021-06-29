#include <stdio.h>

int n[100000],q;

int binarysearch(int key)
{
  int left=0;
  int right=q;
  int mid;

  while(left < right)
    {
      mid = (left + right) / 2;
      if (key == n[mid]) return 1;
      if (key > n[mid]) left = mid + 1;
      else if(key < n[mid]) right = mid;
    }
  return 0;
}

int main()
{
  int s,t,i,count=0;

  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&n[i]);

  scanf("%d",&t);

  for(i=0;i<t;i++){
    scanf("%d",&s);
  if(binarysearch(s))
        {
          count++;

        }
  }
  printf("%d\n",count);
  return 0;
}

