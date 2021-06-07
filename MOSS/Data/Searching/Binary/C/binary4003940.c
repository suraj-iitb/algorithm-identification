#include<stdio.h>

int main(void)
{
	int i;
	
	int n;
	scanf("%d",&n);
	
	int S[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	int q;
	scanf("%d",&q);
	
	int T[q];
	for(i=0;i<q;i++)
	{
		scanf("%d",&T[i]);
	}
	
	int count=0,x=0;
	
	for(i=0;i<q;i++)
	{
		x=T[i];
		int right=n,left=0;
		int mid=0;
		while(left<right)
		{
			mid=(left+right)/2;
			if(x==S[mid])
			{
				count++;
				break;
			}
			if(x>S[mid])
			{
				left=mid+1;
			}
			else if(x<S[mid])
			{
				right=mid;
			}
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}
