#include<stdio.h>
#define MAX 100000
int main(void)
{
	int i,n1,n2,a[MAX],b[MAX],r,l,mid;
	int count=0;
	
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
		r=n1;
		l=0;
		while(l<r)
		{
			mid=(r+l)/2;
			if(a[mid]==b[i])
			{
				count++;
				break;
			}
		if(a[mid]>b[i])
		{
			r=mid;
		}
		else if(a[mid]<b[i])
		{
			l=mid+1;
		}
		}
	}
	printf("%d\n",count);
	return 0;
}
