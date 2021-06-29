#include <stdio.h>
#include <string.h>


int linearsearch(int s[],int key,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(s[i]==key)
		{
			return 1;
		}
		
	
	}
	return 0;
}


int main (void)
{
	int i,s[100000],n,q,key,c=0;
	
	scanf("%d",&n);
	
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&key);
		c+=linearsearch(s,key,n);
	}
	
	printf("%d\n",c);
}
		
