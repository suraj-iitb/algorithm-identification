#include <stdio.h>

int main()
{
  int left,right,mid,n1,n2,a[100000],b[100000],i,cnt=0;
  scanf("%d",&n1);
  for(i=0;i<n1;i++)
    {
      scanf("%d",&a[i]);
    }
  scanf("%d",&n2);
  for(i=0;i<n2;i++)
    {
      scanf("%d",&b[i]);
    }
  for(i=0;i<n2;i++)
    {
      left=0;
      right=n1;
      while(left<right)
	{
	  mid = (left+right)/2;
	  if(a[mid]==b[i])
	    {
	      cnt++;
	      break;
	    }
	  else if(b[i]<a[mid])
	    {
	      right = mid;
	    }
	  else left = mid+1;
	}
    }
  printf("%d\n",cnt);

  return 0;
}

