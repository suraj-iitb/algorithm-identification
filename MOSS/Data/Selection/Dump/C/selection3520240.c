#include<stdio.h>
int main(void)
{
	int n;
	int a[100];
	int i,j,minj,s,c=0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		minj=i;
		
		for(j=i;j<n;j++)
		{
			if(a[j]<a[minj])
			{
				minj=j;
			}
		}
		if(a[i]>a[minj])
		{
			s=a[i];
			a[i]=a[minj];
			a[minj]=s;
			c++;
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i!=n-1)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}
	printf("%d\n",c);
	
	return 0;
}
