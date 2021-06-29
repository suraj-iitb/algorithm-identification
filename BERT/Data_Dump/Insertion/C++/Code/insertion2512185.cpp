#include<iostream>
#include<stdio.h>
using namespace std; 
int main()
{
	int n,i,j;
	cin>>n;
	int a[200]={0};
	for(i=0;i<n;i++)  cin>>a[i];
	for(j=0;j<n-1;j++)
	{
		printf("%d ",a[j]);
	}
	printf("%d",a[n-1]);
	printf("\n");
	for(i=1;i<n;i++)
	{
		int v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for(j=0;j<n-1;j++)
		{
			printf("%d ",a[j]);
		}
		printf("%d",a[n-1]);
		printf("\n");
	}
	return 0;
} 
