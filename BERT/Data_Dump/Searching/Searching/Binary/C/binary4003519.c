#include<stdio.h>

int main()
{
	int s[100000],t[100000],n,q,l,r,mid,count=0;
	
	scanf("%d",&n);
	
	for(int i = 0; i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	
	scanf("%d",&q);
	
	for(int i = 0;i<q;i++)
	{
		scanf("%d",&t[i]);
	}
	
	for(int i = 0; i<q;i++)
	{
		l=0;
		r=n;
		while(l<r)
		{
			mid = (l+r)/2;
			if(s[mid]==t[i])
			{
				count++;
				break;
			}
			if(t[i]>s[mid])
			{
				l = mid+1;
			}
			else if (t[i] < s[mid])
			{
				r = mid;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
			
