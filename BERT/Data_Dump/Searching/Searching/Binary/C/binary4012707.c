#include <stdio.h>

int A[10000000];
int n;

int BS(int key)
{
	int l=0;
	int r=n;
	int m;
	
	while (l<r){
		m=(l+r)/2;
		if(key==A[m])
		{
			return 1;
		}
		if(key>A[m])
		{
			l=m+1;
		}
		else if(key<A[m])
		{
			r=m;
		}
	}
	return 0;
}


int main()
{
	int i,j,k,c=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	scanf("%d",&j);
	for(i=0;i<j;i++)
	{
		scanf("%d",&k);
		if(BS(k))
		{
			c=c+1;
		}
	}
	
	printf("%d\n",c);
	
	return 0;
}


