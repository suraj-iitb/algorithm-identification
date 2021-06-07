#include<stdio.h>

int linearSearch(int A[], int n, int key)
{
	int i=0;
	
	A[n]=key;
	
	while(A[i]!=key)
	{
		i++;
	}
		
	if(i!=n)
		return 1;
	
		
	
	return -1;
	
	
	
}



int main(void)
{
	int n,q,i,c=0;
	
	scanf("%d",&n);
	
	int S[n];
	for(i=0; i<n; i++)
	{
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	
	int T[q];
	for(i=0; i<q; i++)
	{
		scanf("%d",&T[i]);
	}
	
	for(i=0; i<q; i++)
	{
		if(linearSearch(S,n,T[i])==1)
			c++;
	}
	
	printf("%d\n",c);
	
	return 0;
}
