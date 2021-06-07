#include <stdio.h>

int binarysearch(int a[] , int n , int key);

int main(void)
{
	int i;
	int n;
	scanf("%d",&n);
	int s[n];
	int j=0;
	for( i = 0; i < n; i++)
	{
		scanf("%d",&s[i]);
	}
	int q;
	scanf("%d",&q);
	int t[q];
	for( i = 0; i < q; i++)
	{
		scanf("%d",&t[i]);
	}
	for( i = 0; i < q; i++)
	{
		j += binarysearch(s,n,t[i]);
	}
	printf("%d\n",j);
	return 0;
}

int binarysearch(int a[] , int n , int key)
{
	int left = 0;
	int right = n;
	int mid;
	while(left < right)
	{
		mid = (left+right)/2;
		if(a[mid] == key)
		{
			return 1;
		}
		else if(key < a[mid])
		{
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return 0;
}
