#include<stdio.h>

int search(int s[],int n,int t)
{
	int i=0;
	s[n]=t;
	
	while(s[i]!=t)
	{
		i++;
	}
	
	return i != n;
}

int main(void)
{
	int n,s[10000];
	int q,t;
	int i,sum=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&t);
		if(search(s,n,t))
		{
			sum++;
		}
	}
	printf("%d\n",sum);
	
	
	return 0;
}
