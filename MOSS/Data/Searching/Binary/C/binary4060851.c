#include <stdio.h>

int main()
{
  int s[100000];
  int t[50000];
  int n=0,q=0,i=0,count=0,left=0,mid=0,right=0;

  //データの入力
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&t[i]);

  //データの探索(二分探索)
  for(i=0;i<q;i++)
    {
      left = 0;
      right = n;
      while(1)
	{
	  if(left>=right)break;
	  mid = (left + right) / 2;
	  if(s[mid]==t[i])
	    {
	      count++;
	      break;
	    }
	  else if(t[i] < s[mid])right = mid;
	  else if (s[mid] < t[i])left = mid + 1;
	}
    }

  //出力
  printf("%d\n",count);
  return 0;
}

