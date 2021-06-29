#include<stdio.h>

int binary_search(int key,int n,int A[]);
int main(void)
{
	int i,key,sum=0,q,n;
	
	scanf("%d",&n);
	
	int A[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	scanf("%d",&q);
	
	for(i=0;i<q;i++)
	{
		scanf("%d",&key);
		
		if(binary_search(key,n,A)==5)
		{
			sum++;
		}	
	}
	
	printf("%d\n",sum);
	
	
	return 0;
}

int binary_search(int key,int n,int A[])
{
	int left=0,right=n,mid,i,t;
	
	while(left<right)
	{
		mid=(left+right)/2;
		
		
		if(A[mid]==key)
		{
			t=5;
			return t;
		}
		
	    if(key>A[mid])
		{
			left=mid+1;
		}else if(key<A[mid])
		{
			right=mid;
		}
	}
	
	return 0;
}								
		

