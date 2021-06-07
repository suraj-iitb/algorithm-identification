#include<stdio.h>

int search(int A[], int n, int k)
{
	int i=0;
	A[n]=k;
	
	while(A[i]!=k)
	{
		
		i++;
	}
	
	return i!=n;
}


int main()
{
	int i,n,A[10000+1],q,k,sum=0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	
	scanf("%d",&q);
	
	for(i=0;i<q;i++)
	{
		scanf("%d",&k);
	
		
		if(search(A,n,k))
		{
			sum++;
		}
		
	}
	
		printf("%d\n",sum);
		
		return 0;
	}
	
	
	
