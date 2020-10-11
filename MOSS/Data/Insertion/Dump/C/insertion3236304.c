#include<stdio.h>
#include<math.h>
#define Number 100000
int main()
{
	int n;
	int c;
	int a[Number];
	int i ,j ,z;
	int v;


	scanf("%d",&n);

	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<=n-1;i++)
	{
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v)
		{
			a[j+1]=a[j];
			j--;
			a[j+1]=v;
		}
		for(z=0;z<n-1;z++)
		{
			printf("%d ",a[z]);
		}
		printf("%d\n",a[n-1]);
		//puts("");
	}
}
