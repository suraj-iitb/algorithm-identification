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
	for(i=0;i<q;i++)
	{
		count2=0;
		for(j=0;j<n;j++)
		{
			if(t[i]==s[j])
			{
				if(count2==0)
				{
					count++;
					count2++;
				}
			}
		}
	}
	printf("%d\n",count);
	return 0;
}

