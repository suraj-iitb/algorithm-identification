#include<stdio.h>

int main(void)
{
	int i,j,n,q,S[100000],T[50000],count=0,left,right,mid=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	for(j=0;j<q;j++)
	{
		scanf("%d",&T[j]);
	}
	
	for(j=0;j<q;j++)
	{
		left=0;
		right=n;
		while(left<right)
		{
			mid=(left+right)/2;
			if(S[mid]==T[j])
			{
				count++;
				left=right;
			}
            else if(T[j]<S[mid])
			{
            	right=mid;
            }
			else
			{
          		left=mid+1;
			}
		}
	}
	printf("%d\n",count);
	
	return 0;
}