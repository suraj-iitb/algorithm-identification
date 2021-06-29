#include<stdio.h>
int main()
{
	int sort[100]={0};
	int n,i,j,k,a=0,count=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&sort[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=0;j--)
		{
			if(sort[j-1]>sort[j])
			{
				a=sort[j-1];
				sort[j-1]=sort[j];
				sort[j]=a;
				count++;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d",sort[i]);
		if(i<n-1)
		{
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",count);
	return 0;
}
