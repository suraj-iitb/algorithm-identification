#include<stdio.h>
int main()
{
	int a[100];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for (int i = 0;i<n-1;i++)	printf("%d ",a[i]);
		printf("%d",a[n-1]);
		printf("\n");
	for	(int i =1;i<n;++i)
	{
		
	for(int j = i - 1; j >=0;j--)
	{
		if(a[j+1]<a[j])
		{
			int tem = a[j+1];
			a[j+1] = a[j];
			a[j] = tem;
		}
	}
	for (int i = 0;i<n-1;i++)	printf("%d ",a[i]);
		printf("%d",a[n-1]);
		printf("\n");
}

 } 
