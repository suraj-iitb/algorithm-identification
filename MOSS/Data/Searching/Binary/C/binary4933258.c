#include <stdio.h>


binarySearch(int s[],int key,int n)
{
	int left=0,right=n,mid;
	
	
	while(left<right)
	{
		mid=(right+left)/2;
		
		if(s[mid]==key)
		{
			return 1;
		}
		else if(key>s[mid])
		{
			left=mid+1;
		}
		else
		{
			right=mid;
		}
		
	}
	
	return 0;
}
		


int main(void)
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
		c+=binarySearch(s,key,n);
	}
	
	printf("%d\n",c);
}
