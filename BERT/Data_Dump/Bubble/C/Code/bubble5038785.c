#include <stdio.h>

int main()
{
	int n,a[100];
	scanf("%d",&n);
	
	for(int i=0;i<300;i++)
	scanf("%d",&a[i]);

	int flag=1,count=0;
	while(flag)
	{  flag=0;
		for(int t=0;t<n-1;t++)
		if(a[t]>a[t+1])
		{
			int temp=a[t];
			a[t]=a[t+1];
			a[t+1]=temp;
			flag=1;
			count++;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i<n-1)printf(" ");
	}
	printf("\n%d\n",count);
	return 0;
}

