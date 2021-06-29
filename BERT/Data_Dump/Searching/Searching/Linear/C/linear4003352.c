#include <stdio.h>

int main()
{
	int n,q,s[100000],t[100000],count;
	
	scanf("%d",&n);

	for(int i=0; i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	
	scanf("%d",&q);
	
	count = 0;
	
	for(int i = 0;i<q;i++)
	{
		scanf("%d",&t[i]);
		
		for(int j=0;j<n;j++)
		{
			if(s[j] == t[i])
			{
				count++;
			    break;
			}
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}
