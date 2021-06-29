#include <stdio.h>

int s[100000],n;

int binarysearch(int s[],int key)
{
	int left = 0;
	int right = n;
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(s[mid] == key) return 1;
		else if(key < s[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return 0;
}

int main()
{
	int i,q,key,cnt = 0;
	
	scanf("%d",&n);
	for(i = 0; i < n; i++) scanf("%d",s + i);
	
	scanf("%d",&q);
	for(i = 0; i < q; i++)
	{
		scanf("%d",&key);
		if(binarysearch(s,key)) cnt++;
	}
	
	printf("%d\n",cnt);
	
	return 0;
}
