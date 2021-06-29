#include<stdio.h>
#include<math.h>
#define Number 100000
int main()
{
	int n;
	int c=0;
	int BB[Number];
	int i ,j ,z;
	int temp=0;


	scanf("%d",&n);

	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&BB[i]);
	}

	for(i=0;i<=n-1;i++)
	{
		for(j=n-1;j>=i+1;--j)
		{
			if (BB[j-1] > BB[j])
			{
				temp=BB[j-1];
				BB[j-1]=BB[j];
				BB[j]=temp;
				c++;
			}
		}
	}

		for(z=0;z<n-1;z++)
	{
		printf("%d ",BB[z]);
	}

	printf("%d\n",BB[n-1]);
	printf("%d\n",c);

	}
