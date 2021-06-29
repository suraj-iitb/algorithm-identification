#include <stdio.h>
#define MAX 10000
int main(void)
{
	int i,j,n1,n2,a[MAX],b[MAX];
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
		for(j=0;j<n1;j++)
		{
			if(a[j]==b[i])
			{
				count++;
				break;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
