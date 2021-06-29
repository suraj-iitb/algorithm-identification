#include<stdio.h>
int ans = 0;
int a[100000];
int num;
int  binsearch(int key)
{
	int mid;
	int left = 0;
	int right = num ;
	while (left<right)
	{
		mid = (left + right) / 2;
		if (key < a[mid])
		{
			right = mid;
		}
		else if (key > a[mid])
		{
			left = mid+1;
		}
		else if (key == a[mid])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int i;
	int n;
	int j;
	int key;
	scanf("%d", &num);
	for (i = 0;i < num;i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &n);
	for (j = 0;j < n;j++)
	{
		scanf("%d", &key);
		if (binsearch(key) )
		{
			ans++;
		}
	}	
	printf("%d\n", ans);
    return 0;
}

