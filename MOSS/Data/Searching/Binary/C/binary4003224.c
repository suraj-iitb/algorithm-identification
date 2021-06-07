#include<stdio.h>

int S[100000],T[100000],n;

int binarysearch(int key)
{
	int left=0;
	int mid=0;
	int right=n;

	while(left<right)
	{
		mid=(left+right)/2;

		if(S[mid]==key)
		{
			return 1;
		}
		else if(key<=S[mid])
		{
			right=mid;
		}
		else
		{
			left=mid+1;
		}
	}
	return 0;
}
int main()
{
	int i,j,q,c=0;

	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		scanf("%d",&S[i]);
	}

	scanf("%d",&q);

	for(i=0; i<q; i++)
	{
		scanf("%d",&j);
		if(binarysearch(j))
		{
			c++;
		}
	}
	printf("%d\n",c);

	return 0;
}





