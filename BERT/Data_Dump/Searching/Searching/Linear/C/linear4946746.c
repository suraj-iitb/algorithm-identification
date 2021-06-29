#include<stdio.h>

int search(int A[],int n,int key)
{
	int i;
	A[n]=key;
	
	i=0;
	while(A[i]!=key)
	{
		i++;
	}
	return i!=n;
}
int main(void)
{
	int i,n,A[10000],q,key,c;
	
	c=0;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&key);
		if(search(A,n,key))
		{
			c++;
		}
	}
	printf("%d\n",c);
	
	return 0;
}
