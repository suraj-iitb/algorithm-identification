#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int a[n];
	int s;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int t;
	for(i=0;i<n;i++)
	{
		t=a[i];
		for(j=i-1;j>=0&&t<a[j];j--)
		    a[j+1]=a[j];
		a[j+1]=t;
		for(s=0;s<n;s++)
		{
			if(s>0)
			   printf(" ");
			printf("%d",a[s]);
		}
		printf("\n"); 
	} 
	
	return 0;
} 
