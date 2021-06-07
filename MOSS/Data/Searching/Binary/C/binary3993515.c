#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int n;
	int q;
	int i;
	scanf("%d",&n);
	int s[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	scanf("%d",&q);
	int t[q];
	for(i=0;i<q;i++)
	{
		scanf("%d",&t[i]);
	}
	int j;
	int count=0;
	int count2;
	
	int left;
	int right;
	int mid;
	for(i=0;i<q;i++)
	{
		left =0;
		right = n;
		count2=0;
		while(left<right)
		{
			mid=(left+right)/2;
			if(s[mid]==t[i])
			{
				if(count2==0)
				{
					count++;
					break;
				}
			}
			else if (t[i]<s[mid])
			{
				right = mid;
			}
			else if(t[i]>s[mid])
			{
				left = mid +1;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}

