#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[150],i,j,n;
void output()
{
	for(j=1;j<=n;j++)
	{
		printf("%d",a[j]);
		if(j!=n)
			printf(" ");
	}
}
void sort()
{
	int v;
	for(i=2;i<=n;i++)
	{
		v=a[i];
		j=i-1;
		while(j>=1 && a[j]>v)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		output();
		printf("\n");
	}
	return;
}
int main()
{
	scanf("%d",&n);
	//我喜欢从1开始计数，就把a[0]给废掉了
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		printf("%d",a[i]);
		if(i!=n)
			printf(" ");
	}
	printf("\n");
	sort();
	return 0;
}
